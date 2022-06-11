#include <iostream>

int main() {
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;
    int guess = 3.9832;
    int debt = 7.2E12;
    cout << "tree = " << tree << "\n";
    cout << "guess = " << guess << "\n";
    cout << "debt = " << debt << "\n";

    return 0;
}

/*
output:
    assign.cc:8:17: warning: implicit conversion from 'double' to 'int' changes value from 3.9832 to 3 [-Wliteral-conversion]
    int guess = 3.9832;
        ~~~~~   ^~~~~~
    assign.cc:9:16: warning: implicit conversion of out of range value from 'double' to 'int' is undefined [-Wliteral-conversion]
        int debt = 7.2E12;
            ~~~~   ^~~~~~
    2 warnings generated.
    tree = 3.000000
    guess = 3
    debt = 4098
*/