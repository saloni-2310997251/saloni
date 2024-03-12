#include <iostream>
#include <string>
using namespace std;
class User {
private:
    string name;
    int birth_year;
    int birth_month;
    int birth_day;
    double salary;

public:
    
    User(const string& n, int year, int month, int day, double sal)
        : name(n), birth_year(year), birth_month(month), birth_day(day), salary(sal) {}

    
    int operator==(const User& other) const {
        if (birth_year < other.birth_year ||
            (birth_year == other.birth_year && birth_month < other.birth_month) ||
            (birth_year == other.birth_year && birth_month == other.birth_month && birth_day < other.birth_day)) {
            return 1; 
        } else if (birth_year == other.birth_year && birth_month == other.birth_month && birth_day == other.birth_day) {
            return 0; 
        } else {
            return -1; 
        }
    }

   
    double operator+(const User& other) const {
        return (salary + other.salary) / 2.0;
    }

    
    User operator+(int percentage) const {
        User newUser = *this; 
        newUser.salary *= (1 + (percentage / 100.0)); 
        return newUser;
    }

   
    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Birthdate: " << birth_year << "-" << birth_month << "-" << birth_day << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    
    User user1("John", 1990, 5, 15, 50000.0);
    User user2("Alice", 1985, 8, 20, 60000.0);

    int result = user1 == user2;
	cout << "Comparison result: " << result << endl;

    double average_sal = user1 + user2;
    cout << "Average Salary: " << average_sal << endl;

    User user1WithIncrement = 5 + user1;
    User user2WithIncrement = 10 + user2;

    cout << "Details after increment for User 1:" << endl;
    user1WithIncrement.displayDetails();

    cout << "Details after increment for User 2:" << endl;
    user2WithIncrement.displayDetails();

    return 0;
}

