#include <iostream>
using namespace std;

int sumOfSeries(int n) {
    int sum = 0;
    int termSum = 0;
    
    for (int i = 1; i <= n; ++i) {
        termSum += i; 
        sum += termSum; 
    }
    return sum;
}

int main() {
    int n;
   e integer: ";
    cin >> n;
    if (n <= 0) {
        cout << "Input should be a positive integer.\n";
        return 1; 
    }
    cout << "Sum of the series: " << sumOfSeries(n) << endl;
    return 0;
}

