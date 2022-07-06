// usetime1.cc -- using the second draft of the time class
// compile usetime1.cc and mytime1.cc together
#include <iostream>
#include "mytime1.h"

int main() {
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "coding.Sum(fixing) = ";
    total.Show();
    cout << endl;

    return 0;
}