// address.cc -- using the & operator to find address
#include <iostream>

int main() {
    using namespace std;

    int donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
    // NOTE: you may need to use unsigned (&donuts)
    // and unsigned (&cups)
    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;

    return 0;
}
/*
output:
    donuts value = 6 and donuts address = 0x7ff7b917f178
    cups value = 4.5 and cups address = 0x7ff7b917f170
*/