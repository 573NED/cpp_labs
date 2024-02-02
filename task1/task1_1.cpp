#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string inputString = "The quick brown ,, fox jumps over the lazy dog";
    std::istringstream iss(inputString);
    std::vector<std::string> words;

    do {
        std::string word;
        iss >> word;
        words.push_back(word);
    } while (iss);

    std::string resultString;
    for (const std::string& word : words) {
        if (word.length() % 2 == 0) {
            resultString += word + " ";
        }
    }

    std::cout << "input: " << inputString << std::endl;
    std::cout << "result: " << resultString << std::endl;

    return 0;
}