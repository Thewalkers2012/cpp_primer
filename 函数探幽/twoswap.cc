// twoswap.cc -- specialization override a template
#include <iostream>

template <class Any>
void Swap(Any &a, Any &b);

struct job {
    char name[40];
    double salary;
    int floor;
};

// explicit specialization
template<> void Swap<job>(job &j1, job &j2);

void Show(job &j);

int main() {
    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10, j = 20;
    cout << "i = " << i << " j = " << j << endl;
    cout << "Using compiler-generated int swapper: \n";
    Swap(i, j);
    cout << "Now i = " << i << " j = " << j << endl;

    job jack = {"Jack", 7300.60, 7};
    job john = {"John", 78060.72, 9};
    cout << "Before job swapping: \n";
    Show(jack);
    Show(john);
    Swap(jack, john); // use void Swap(job &a, job &b);

    cout << "After job swapping: \n";
    Show(jack);
    Show(john);

    return 0;
}

template <class Any>
void Swap(Any &a, Any &b) {
    Any temp;
    temp = a;
    a = b;
    b = temp;
}

// swaps just the salary and floor fields of a job structure
template<> void Swap<job>(job &j1, job &j2) {
    double t1;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;

    int t2;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j) {
    using namespace std;
    cout << j.name << ": $" << j.salary 
        << " on floor " << j.floor << endl;
}

/*
output:
    i = 10 j = 20
    Using compiler-generated int swapper: 
    Now i = 20 j = 10
    Before job swapping: 
    Jack: $7300.60 on floor 7
    John: $78060.72 on floor 9
    After job swapping: 
    Jack: $78060.72 on floor 9
    John: $7300.60 on floor 7
*/