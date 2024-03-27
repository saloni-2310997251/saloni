//Example : Addition Operator Overloading

#include <iostream>
using namespace std;


class MyNumber;


MyNumber operator+(const MyNumber& num1, const MyNumber& num2);


class MyNumber {
private:
    int value;

public:
   
    MyNumber(int val) : value(val) {}

   
    int getValue() const {
        return value;
    }

    
    friend MyNumber operator+(const MyNumber& num1, const MyNumber& num2);
};


MyNumber operator+(const MyNumber& num1, const MyNumber& num2) {
   
    int sum = num1.value + num2.value;
    return MyNumber(sum);
}

int main() {
   
    MyNumber num1(5);
    MyNumber num2(10);

    
    MyNumber result = num1 + num2;

    
    cout << "Result of addition: " << result.getValue() << endl;

    return 0;
}

