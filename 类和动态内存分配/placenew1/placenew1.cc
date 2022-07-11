// placenew1.cc -- new, placement new, no delete
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
    pc1 = new (buffer)JustTesting;
    pc2 = new JustTesting("Heap1", 20);

    cout << "Memory block addresses:\n" << "buffer: "
        << (void*)buffer << " heap: " << pc2 << endl;

    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    pc3 = new (buffer)JustTesting("Bad Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc2->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;
    delete pc4;
    delete []buffer;

    return 0;
}

/*
output:
Just Testing constructed
Heap1 constructed
Memory block addresses:
buffer: 0x7fa167804080 heap: 0x600003d14000
Memory contents:
0x7fa167804080: Just Testing, 0
0x600003d14000: Heap1, 20
Bad Idea constructed
Heap2 constructed
Memory contents:
0x7fa167804080: Heap1, 20
0x600003d14020: Heap2, 10
Heap1 destroyed
Heap2 destroyed
*/