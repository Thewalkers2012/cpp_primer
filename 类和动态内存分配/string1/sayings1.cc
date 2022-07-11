// sayings1.cc -- using expanded String class
// compile with string1.cc
#include <iostream>
#include "string1.h"

const int ArSize = 10;

const int MaxLen = 81;

int main() {
    using std::endl;
    using std::cout;
    using std::cin;

    cout << "Hi, what's your name?\n>>";

    String name;
    cin >> name;

    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:\n";

    String sayings[ArSize];
    char temp[MaxLen];

    int i;
    for (i = 0; i < ArSize; i++) {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n') {
            continue ;
        }
        if (!cin || temp[0] == '\0') {
            break ;
        } else {
            sayings[i] = temp;
        }
    }

    int total = i;
    cout << "Here are your sayings:\n";
    for (i = 0; i < total; i++) {
        cout << sayings[i][0] << ": " << sayings[i] << endl;
    }

    int shortest = 0;
    int first = 0;
    for (int i = 1; i < total; i++) {
        if (sayings[i].length() < sayings[shortest].length()) {
            shortest = i;
        }
        if (sayings[i] < sayings[first]) {
            first = i;
        }
    }

    cout << "Shorteest saying:\n" << sayings[shortest] << endl;
    cout << "First alphabetically:\n" << sayings[first] << endl;
    cout << "This program used " << String::HowMany()
        << " String objects. Bye.\n";


    return 0;
}


/*
output:
Hi, what's your name?
>>Misty Gutz
Misty Gutz, please enter up to 10 short sayings <empty line to quit>:
1: a fool and his money are sonn parted
2: panny wise, pound foolish
3: the love of money is the root of much evil
4: out of sight, out of mind
5: absence makes the heart grow fonder
6: absinthe 
7: 
Here are your sayings:
a: a fool and his money are sonn parted
p: panny wise, pound foolish
t: the love of money is the root of much evil
o: out of sight, out of mind
a: absence makes the heart grow fonder
a: absinthe 
Shorteest saying:
absinthe 
First alphabetically:
absinthe 
This program used 11 String objects. Bye.

*/