// arrstruc.cc -- an array of structure
#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;

    inflatable guests[2] = {
        {"Babi", 0.5, 21.99},
        {"Godzilla", 2000, 565.99},
    };

    cout << "The guests " << guests[0].name
        << " and " << guests[1].name << "\nhave a combined volume of "
        << guests[0].volume + guests[1].volume << " cubic feet.\n";

    return 0;
}

/*
output:
The guests Babi and Godzilla
have a combined volume of2000.5 cubic feet
*/