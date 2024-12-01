#include <iostream>
#include "Fraction.h"
using std::cout;
using std::cin;

int main()
{
    int k;
    Fraction a, b, c;
    cout << "enter a:\n";
    a.input();
    cout << "\nenter b:\n";
    b.input();
    c = a + b;
    cout << "\na+b = ";
    c.output();
    c = a - b;
    cout << "\na-b = ";
    c.output();
    c = a * b;
    cout << "\na*b = ";
    c.output();
    c = a / b;
    cout << "\na/b = ";
    c.output();
    if (a > b) {
        cout << "\na > b";
    }
    if (a < b) {
        cout << "\na < b";
    }
    if (a == b) {
        cout << "\na == b";
    }
    if (a != b) {
        cout << "\na != b";
    }
    cout << "\nenter the degree - ";
    cin >> k;
    cout << "a^k = ";
    c = a ^ k;
    c.output();
    cout << "\nwhole part = " << a.wholePart();
    return 0;
}