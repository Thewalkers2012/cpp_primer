// strings.cc -- storing strings in an array
#include <iostream>
#include <cstring>

int main() {
    using namespace std;

    const int Size = 15;
    char name1[Size]; // empty array
    char name2[Size] = "C++owboy"; // initialize array
    // NOTE: some implementations may require the static keyword
    // to initialize the array name2

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name\n";

    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is shored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\n';
    cout << "Here are the first 3 characters of my name";
    cout << name2 << "\n";

    return 0;
}

/*
output:
    Howdy! I'm C++owboy! What's your name
    cpp
    Well, cpp, your name has 3 letters and is shored
    in an array of 15 bytes.
    Your initial is c.
    Here are the first 3 characters of my nameC++
    wboy
*/