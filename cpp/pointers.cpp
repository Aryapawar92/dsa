// Pointers

#include <bits/stdc++.h>
using namespace std;

int main() {
    string food = "Pizza";
    string* ptr = &food; // // A pointer variable, with the name ptr, that stores the address of food

    cout << food << "\n";   // Prints Pizza
    cout << &food << "\n";  // Prints memory address
    cout << ptr << "\n";
    cout << *ptr << "\n"; // this causes dereferencing

    return 0;
}