// assign_st.cc -- assigning structures
#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;

    inflatable bouquet = {
        "sunflowers",
        0.20,
        12.49,
    };

    inflatable choice;
    cout << "bouquet: " << bouquet.name << " for $";
    cout << bouquet.price << endl;
    choice = bouquet;
    cout << "choic: " << choice.name << " for $";
    cout << choice.price << endl;

    return 0;
}

/*
output:
    bouquet: sunflowers for $12.49
    choic: sunflowers for $12.49
*/