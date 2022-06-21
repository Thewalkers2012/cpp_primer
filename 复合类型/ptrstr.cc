// ptrstr.cc -- using pointers to strings
#include <iostream>
#include <cstring>

int main() {
    using namespace std;

    char animal[20] = "bear";
    const char* bird = "wren";
    char *ps;

    cout << animal << " and ";
    cout << bird << "\n";
    // cout << ps << "\n" may display garbage, may cause a crash

    cout << "Enter a kind of animal: ";
    cin >> animal; // ok if input < 20 chars

    // cin >> ps; Too horrible a blunder to try; 
    // ps doesn't point to allocated space

    ps = animal;
    cout << ps << "s!\n"; // ok same as using animal
    cout << "Before using strcpy(): \n";

    cout << animal << " at " << (int*)animal << endl;
    cout << ps << " at " << (int*)ps << endl;

    ps = new char[strlen(animal) + 1]; // get new storage
    strcpy(ps, animal);

    cout << "After using strcpy(): \n";
    cout << animal << " at " << (int*)animal << endl;
    cout << ps << " at " << (int*)ps << endl;

    delete []ps;

    return 0;
}

/*
output:
    bear and wren
    Enter a kind of animal: bear  
    bears!
    Before using strcpy(): 
    bear at 0x7ff7b1cce160
    bear at 0x7ff7b1cce160
    After using strcpy(): 
    bear at 0x7ff7b1cce160
    bear at 0x6000013ec000
*/