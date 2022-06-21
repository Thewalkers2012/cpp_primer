// instr3.cc -- reading more than one work with get() & get()
#include <iostream>

int main() {
    using namespace std;

    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name: \n";
    cin.get(name, ArSize).get(); // read string, new line
    cout << "Enter your favorite dessert: \n";
    cin.get(dessert, ArSize).get();
    cout << "I have some dilicious " << dessert;
    cout << " for you. " << name << ".\n";

    return 0;
}

/*
output:
    Enter your name: 
    Mai Parfait
    Enter your favorite dessert: 
    Chocolate Mousse
    I have some dilicious Chocolate Mousse for you. Mai Parfait.
*/