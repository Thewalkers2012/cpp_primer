// 用 cin 输入字符串数据时，如果字符串中含有
// 空白字就不能完整输入。因为遇到空白字符时
// 就不能够完整输入，cin 就认为字符串结束了
#include <iostream>

int main(int argc, char **argv)
{
    char a[50];
    std::cout << "please input a string: ";
    std::cin >> a;

    std::cout << a << std::endl;

    return 0;
}