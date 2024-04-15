#include <iostream>
#include <string>
using namespace std;

class StringAnalyzer {
private:
    string* strPtr;

public:
    StringAnalyzer(const string& str) {
        strPtr = new string(str);
    }

    ~StringAnalyzer() {
        delete strPtr;
    }

    int countWords() const {
        if (strPtr == nullptr || strPtr->empty()) {
            return 0;
        }

        int wordCount = 1;
        bool inWord = false;
        for (char c : *strPtr) {
            if (isspace(c)) {
                inWord = false;
            } else {
                if (!inWord) {
                    ++wordCount;
                    inWord = true;
                }
            }
        }
        return wordCount;
    }
};

int main() {
    StringAnalyzer analyzer("Hello, how are you?");

    cout << "Total words in the string: " << analyzer.countWords() << endl;

    return 0;
}

