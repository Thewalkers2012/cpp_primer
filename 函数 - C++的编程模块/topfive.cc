// topfive.cc -- handling an array of string object
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 5;

void display(const string sa[], int n);

int main() {
    string list[SIZE]; // an array holding 5 string object

    cout << "Enter you " << SIZE << " favorite astronomical sights:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }

    cout << "Your list:\n";
    display(list, SIZE);

    return 0;
}

void display(const string sa[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": " << sa[i] << endl;
    }
}

/*
output:
Enter you 5 favorite astronomical sights:
1: qweqwe
2: 2312
3: dsfsdaf
4: qwewerew
5: thewalkers
Your list:
1: qweqwe
2: 2312
3: dsfsdaf
4: qwewerew
5: thewalkers

*/