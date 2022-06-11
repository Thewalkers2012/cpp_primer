#include <iostream>

int main() {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;

    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub; 
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;

    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;

    return 0;
}
/*
output:
    tub = 3.333333, a million tubs = 3333333.250000,
    and ten million tubs = 33333332.000000
    mint = 3.333333 and a million mints = 3333333.333333
*/

/*
    由于 cout 是打印 6 位小数，在这种情况下，tub 和 mint 都是精确的。
    但当程序乘 100w 之后，tub 在第 7 个 3 之后就与正确值有了误差。
    然而 double 类型变量显示了 13 个 3，因此它至少有 13 位是精确的，因为系统确保了 15 位的有效位。
*/