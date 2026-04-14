#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool compareLengths(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot find input.txt" << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create output.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> sentences;
    std::string line;

    std::cout << "Reading sentences..." << std::endl;
    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            sentences.push_back(line);
        }
    }

    std::cout << "Processing..." << std::endl;
    std::reverse(sentences.begin(), sentences.end());
    std::stable_sort(sentences.begin(), sentences.end(), compareLengths);

    std::cout << "Writing result..." << std::endl;
    for (const std::string& s : sentences) {
        outputFile << s << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Success! Results saved in output.txt" << std::endl;

    return 0;
}