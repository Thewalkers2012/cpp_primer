// placenew2.cc -- new, placement new, no delete
#include <iostream>
#include <string>
#include <new>

using namespace std;

const int BUF = 512;

class JustTesting {
private:
    string words;
    int number;

public:
    JustTesting(const string &s = "Just Testing", int n = 0) {
        words = s;
        number = n;
        cout << words << " constructed\n";
    }

    ~JustTesting() {
        cout << words << " destroyed\n";
    }

    void Show() const {
        cout << words << ", " << number << endl;
    }
};

int main() {
    char *buffer = new char[BUF];

    JustTesting *pc1, *pc2;
}