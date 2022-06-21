// addpntrs.cc -- pointer addition
#include <iostream>

int main() {
    using namespace std;

    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stack[3] = {3, 2, 1};

    // Here are two ways to get the address of an array
    double *pw = wages; // name of an array = address
    short *ps = &stack[0];  // or use address operator

    // with array element
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";


    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";
    cout << "stacks[0] = " << stack[0]
        << ", stack[1] = " << stack[1] << endl;
    cout << "access two elements with array notation\n";
    cout << "*stacks = " << *stack
        << ", *(stack + 1) = " << *(stack + 1) << endl;

    cout << sizeof(wages) << " = size of wage array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";

    return 0;
}

/*
output:
    pw = 0x7ff7b903e160, *pw = 10000
    add 1 to the pw pointer:
    pw = 0x7ff7b903e168, *pw = 20000

    ps = 0x7ff7b903e156, *ps = 3
    add 1 to the ps pointer:
    ps = 0x7ff7b903e158, *ps = 2

    access two elements with array notation
    stacks[0] = 3, stack[1] = 2
    access two elements with array notation
    *stacks = 3, *(stack + 1) = 2
    24 = size of wage array
    8 = size of pw pointer
*/
