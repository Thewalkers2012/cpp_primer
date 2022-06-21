// instr1.cc -- reading more than one string
#include <iostream>

int main() {
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name: \n";    
    cin >> name;
    cout << "Enter your favorite dessert: \n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << "\n";

    return 0;
}

/*
output:
    Enter your name: 
    cpp
    Enter your favorite dessert: 
    i like
    I have some delicious i for you, cpp
*/