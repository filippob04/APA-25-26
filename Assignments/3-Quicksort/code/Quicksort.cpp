#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>

const std::string PATH = "../data/"; // Relative path
std:: random_device rd; // random number generator better than rand() 
std::mt19937 gen(rd());

// returns a vector<int>
std::vector<size_t> readFile (const std::string& fileName) {
    std::vector<size_t> s;
    std::ifstream file_in(fileName);
    if (!file_in) {std::cerr << "Error opening file" << fileName << "\n"; return s;} // Error handling

    size_t n;
    while (file_in >> n) {
        s.push_back(n);
    }
    std::cout << "Sequence obtained\n";
    file_in.close();
    return s;
}
// writes onto file
void outFile (const std::string& fileName, const std::vector<size_t>& s) {
    std::ofstream file_out(fileName);
    if (!file_out) {std::cerr << "Error opening file" << fileName << "\n"; return;} // Error handling

    for (size_t i = 0; i < s.size(); i++) {
        file_out << s.at(i) << "\n";
    }
    std::cout << "Vector succesfully saved\n";
    file_out.close();
}
// swap function
void swap (std::vector<size_t>& s, size_t a, size_t b) {
    size_t tmp = s.at(a);
    s.at(a) = s.at(b);
    s.at(b) = tmp;
}
// Las Vegas Quicksort
void r_quick_sort(std::vector<size_t>& s, size_t start, size_t end, size_t& count) {
    if (start < end) {
        std::uniform_int_distribution<> d(start, end);

        size_t pivot = d(gen); // random index
        swap(s, start, pivot);
        pivot = start;

        size_t i = start + 1;
        size_t j = i;

        while (j <= end) {
            count++;
            if (s.at(j) < s.at(pivot)) {
                swap(s, i, j);
                i++;
            }
            j++;
        }
        swap(s, pivot, i-1);
        pivot = i-1;
        if (pivot > start) {r_quick_sort(s, start, pivot - 1, count);}
        if (pivot < end) {r_quick_sort(s, pivot + 1, end, count);}
    }
}
size_t lv_quicksort(std::vector<size_t>& s) {
    size_t count = 0;
    if (s.size() <=1) {return count;}
    r_quick_sort(s, 0, s.size() - 1, count);
    return count;
}
// returns number of comparisons of LVQuicksort(s) K iterations
const size_t K = 100000;
std::vector<size_t> iter_lvqs(std::vector<size_t>& s, const size_t K) {
    std::vector<size_t> x;
    std::cout << "Starting Algorithm for " << K << " iterations\n";
    for (size_t i = 0; i < K; i++) {
        std::vector<size_t> s_copy = s;
        x.push_back(lv_quicksort(s_copy));
        std::cout << "Iteration " << i << "\n";
    }
    std::cout << "Algorithm finished\n";
    return x;
}
int main () {
    std::vector<size_t> s; // input sequence
    std::vector<size_t> x; // output vector
    
    std::string input = "out";
    s = readFile(PATH + input + ".txt");

    x = iter_lvqs(s, K);
    
    std::string output = "in";
    outFile(PATH + output + ".txt", x);

    return 0;
}