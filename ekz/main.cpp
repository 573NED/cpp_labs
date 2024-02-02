#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input;
    cout << "input: ";
    getline(cin, input);

    istringstream iss(input);

    string maxWord;
    size_t maxWordIndex = 0;
    string word;
    size_t currentIndex = 0;

    while (iss >> word) {
        ++currentIndex;
        if (word.length() > maxWord.length()) {
            maxWord = word;
            maxWordIndex = currentIndex;
        }
    }

    cout << "max word: " << maxWord << endl;
    cout << "place: " << maxWordIndex << endl;

    return 0;
}
