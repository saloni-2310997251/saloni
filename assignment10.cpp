#include <iostream>
#include <map>
#include <string>
using namespace std;

void searchBook(const map<string, string>& bookList, const string& isbn) {
    auto it = bookList.find(isbn);
    if (it != bookList.end()) {
        cout << "Book Found!" << endl;
        cout << "Title: " << it->second << endl;  
    } else {
        cout << "Book with ISBN " << isbn << " not available in the library." << endl;
    }
}

int main() {
    map<string, string> bookList = {
        {"978-0131101630", "The C++ Programming Language"},
        {"978-0201633610", "Design Patterns: Elements of Reusable Object-Oriented Software"},
        {"978-0201485677", "The Mythical Man-Month: Essays on Software Engineering"},
        
    };
    string isbn;
    cout << "Enter the ISBN of the book you are looking for: ";
    cin >> isbn;
    searchBook(bookList, isbn);
    return 0;
}

