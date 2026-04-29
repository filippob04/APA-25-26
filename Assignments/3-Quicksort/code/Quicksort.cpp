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

// returns a vector of int
std::vector<std::string> readFile (std::string fileName) {
    std::vector<std::string> s;

    std::ifstream file_in(fileName);
    if (!file_in) {std::cerr << "Error opening file\n"; exit(-1);} // kills the process

    std::string n;
    while (file_in >> n) {
        s.push_back(n);
    }

    file_in.close();
    return s;
}

int main () {
    std::vector<std::string> s;
    
    std::string fileName = "out";
    s = readFile(PATH + fileName + ".txt");

    for (unsigned int i = 0; i < s.size(); i++) {
        std::cout << s.at(i) << " ";
    }
    
    return 0;
}