// functemp.cc -- using a function template
#include <iostream>
// function template prototype
template <class Any> // or template Any
void Swap(Any &a, Any &b);

int main() {
    using namespace std;

    int i = 10;
    int j = 20;
    cout << "i = " << i << " j = " << j << ".\n";
    cout << "Using compiler-generated int swapper: \n";
    Swap(i, j);
    cout << "i = " << i << " j = " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x = " << x << " y = " << y << ".\n";
    cout << "Using compiler-generated int swapper: \n";
    Swap(x, y);
    cout << "x = " << x << " y = " << y << ".\n";


    return 0;
}

// function template definition
template <class Any>
void Swap(Any &a, Any &b) {
    Any temp; // temp a variable of tyep Any
    temp = a;
    a = b;
    b = temp;
}

/*
output:
    i = 10 j = 20.
    Using compiler-generated int swapper: 
    i = 20 j = 10.
    x = 24.5 y = 81.7.
    Using compiler-generated int swapper: 
    x = 81.7 y = 24.5.
*/