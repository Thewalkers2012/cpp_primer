// delete.cc -- using the delete operator
#include <iostream>
#include <cstring>

using namespace std;

char* getname(void); // function prototype

int main() {
    char *name; // create pointer but no storage

    name = getname(); // assign address of string to name
    cout << name << " at " << (int*)name << "\n";
    delete []name; // memory free

    name = getname();
    cout << name << " at " << (int*)name << "\n";
    delete []name; // memory free

    return 0;
}

char* getname() {
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;

    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);

    return pn;
}

/*
output:
    Enter last name: thewalkers
    thewalkers at 0x600000428000
    Enter last name: feedback
    feedback at 0x60000042c000
*/
