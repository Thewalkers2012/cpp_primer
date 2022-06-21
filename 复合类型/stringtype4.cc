// stringtype4.cc -- line input
#include <iostream>
#include <cstring>
#include <string>

int main() {
    using namespace std;

    char charr[20];
    string str;

    cout << "Length of string in charr before input: "
        << strlen(charr) << endl;

    cout << "Length of string in str before input: "
        << str.size() << endl;

    cout << "Enter a line of text:\n";
    cin.getline(charr, 20); // indicate maximum length

    cout << "Your entered: " << charr << endl;
    cout << "Enter another line of text: \n";

    cin >> str;
    cout << "Your entered: " << str << endl;

    cout << "Length of string in charr after input: "
        << strlen(charr) << endl;

    cout << "Length of string in str after input: "
        << str.size() << endl;

    return 0;
}

/*
output:
    Length of string in charr before input: 6
    Length of string in str before input: 0
    Enter a line of text:
    peanut butter
    Your entered: peanut butter
    Enter another line of text: 
    hello
    Your entered: hello
    Length of string in charr after input: 13
    Length of string in str after input: 5
*/