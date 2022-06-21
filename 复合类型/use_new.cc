// use_new.cc -- using the new operator
#include <iostream>

int main() {
    using namespace std;

    int *pt = new int;
    *pt = 1001;

    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;

    double *pd = new double;
    *pd = 1000.1;

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;

    cout << "size of pt = " << sizeof(pt) << endl;
    cout << "size of *pt = " << sizeof(*pt) << endl;

    cout << "size of pd = " << sizeof(pd) << endl;
    cout << "size of *pd = " << sizeof(*pd) << endl;

    return 0;
}
/*
64 位操作系统
output:
    int value = 1001: location = 0x60000249c030
    double value = 1000.1: location = 0x60000249c040
    size of pt = 8
    size of *pt = 4
    size of pd = 8
    size of *pd = 8
*/