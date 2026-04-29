/* Ricevere da file sequenza da ordinare
Definire algoritmo LVQuicksort su k = 10^5 iterazioni
output array con numero di confronti per iterazione
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

const std::string PATH = "../data/"; // Relative path

// returns a vector<int>
std::vector<int> readFile (std::string fileName) {
    std::vector<int> s;

    std::ifstream file_in(fileName);
    if (!file_in) {std::cerr << "Error opening file" << fileName << "\n"; return s;} // Error handling

    int n;
    while (file_in >> n) {
        s.push_back(n);
    }

    file_in.close();
    return s;
}
// writes onto file
void outFile (std::string fileName, std::vector<int> s) {
    std::ofstream file_out(fileName);
    if (!file_out) {std::cerr << "Error opening file" << fileName << "\n"; return;} // Error handling

    for (size_t i = 0; i < s.size(); i++) {
        file_out << s.at(i) << "\n";
    }

    file_out.close();
}

int main () {
    std::vector<int> s;
    
    std::string input = "out";
    s = readFile(PATH + input + ".txt");

    for (size_t i = 0; i < s.size(); i++) {
        std::cout << s.at(i) << " ";
    }
    
    std::string output = "in";
    outFile(PATH + output + ".txt", s);

    return 0;
}