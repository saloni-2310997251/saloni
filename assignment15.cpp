#include <iostream>
using namespace std;

class B;

class A {
private:
    int numA;

public:
    A(int numA) : numA(numA) {}
    friend int sum(const A& objA, const B& objB);
};

class B {
private:
    int numB;

public:
    B(int numB) : numB(numB) {}
    friend int sum(const A& objA, const B& objB);
};

int sum(const A& objA, const B& objB) {
    return objA.numA + objB.numB;
}

int main() {
    A objA(5);
    B objB(10);

    int totalSum = sum(objA, objB);
    cout << "Sum of private members: " << totalSum << endl;

    return 0;
}

