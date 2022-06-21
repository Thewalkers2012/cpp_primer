// newstrut.cc -- using new with a structure
#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std; 

    inflatable *ps = new inflatable;
    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20); // method 1 for member access

    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;
    cout << "Enter price: $";
    cin >> ps->price;
    cout << "Name: " << (*ps).name << endl;
    cout << "Volume: " << ps->volume << endl;
    cout << "Price: " << ps->price << endl;

    delete ps;

    return 0;
}

/*
output:
    Enter name of inflatable item: thewalkers
    Enter volume in cubic feet: 20
    Enter price: $39
    Name: thewalkers
    Volume: 20
    Price: 39
*/