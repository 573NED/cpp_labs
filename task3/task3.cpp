#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// Функция для проверки, является ли слово знаком логической операции
bool isLogicalOperator(const std::string& word) {
    // Здесь вы можете добавить другие логические операторы, если необходимо
    std::vector<std::string> logicalOperators = {"&&", "||", "!", "&", "|", "^"};

    return std::find(logicalOperators.begin(), logicalOperators.end(), word) != logicalOperators.end();
}

// Функция для удаления слов-логических операторов из строки
std::string removeLogicalOperators(const std::string& line) {
    std::istringstream iss(line);
    std::ostringstream oss;

    std::string word;
    bool firstWord = true;

    while (iss >> word) {
        if (!isLogicalOperator(word)) {
            if (!firstWord) {
                oss << " ";
            }
            oss << word;
            firstWord = false;
        }
    }

    return oss.str();
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Unable to open files." << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        std::string modifiedLine = removeLogicalOperators(line);
        outputFile << modifiedLine << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Logical operators removed successfully." << std::endl;

    return 0;
}