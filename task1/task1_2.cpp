#include <iostream>
#include <sstream>

class CustomString {
public:
  CustomString(const std::string &str) : content(str) {}

  void processAndPrint() {
    std::istringstream iss(content);
    std::string word;

    std::cout << "input: " << content << std::endl;
    std::cout << "result: ";

    while (iss >> word) {
      if (word.length() % 2 == 0) {
        std::cout << word << " ";
      }
    }

    std::cout << std::endl;
  }

private:
  std::string content;
};

int main() {
  std::string inputString = "The quick brown fox jumps over the lazy dog";
  CustomString customStr(inputString);
  customStr.processAndPrint();

  return 0;
}