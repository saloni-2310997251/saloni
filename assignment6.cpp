#include<iostream>
using namespace std;

class sample {
public:
    int Compute(int (sample::*func)(int), int n) {
        return (this->*func)(n);
    }

    int findFactorial(int n) {
        int fact = 1;
        for(int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
    }

    int findSquare(int n) {
        return n * n;
    }

    int findCube(int n) {
        return n * n * n;
    }
};

int main(int argc, char *argv[]) {
    sample obj;

    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <value>" << endl;
        return 1;
    }

    int N = stoi(argv[1]);

    int resultFactorial = obj.Compute(&sample::findFactorial, N);
    cout << "Factorial of " << N << ": " << resultFactorial << endl;

    int resultSquare = obj.Compute(&sample::findSquare, N);
    cout << "Square of " << N << ": " << resultSquare << endl;

    int resultCube = obj.Compute(&sample::findCube, N);
    cout << "Cube of " << N << ": " << resultCube << endl;

    return 0;
}

