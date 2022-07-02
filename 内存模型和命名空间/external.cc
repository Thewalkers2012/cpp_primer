// external.cc -- external variable
#include <iostream>

using namespace std;

// external variable
double warming = 0.3;

// function prototypes
void update(double dt);

void local();

int main() {
    using namespace std;

    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    local();
    cout << "Global warming is " << warming << " degrees.\n";

    return 0;
}

void update(double dt) {
    extern double warming; // optional redeclaration
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";

}

void local() {
    double warming = 0.8; // optional redeclaration
    cout << "Local warming to " << warming;
    cout << " degrees.\n";
    cout << "But global warming = " << ::warming << " degrees.\n";

}

/*
output:
Global warming is 0.3 degrees.
Updating global warming to 0.4 degrees.
Global warming is 0.4 degrees.
Local warming to 0.8 degrees.
But global warming = 0.4 degrees.
Global warming is 0.4 degrees.
*/