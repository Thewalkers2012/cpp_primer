#include <iostream>

// cin.get(arrayname, size) 把字符输入到 arrayname
// 中，长度不超过 size

int main()
{
    // get() 两个参数

    // 1. 输入串长 < size，输入串长 > arraylength，会
    // 自动扩张 arrayname 大小，使能保存所有数据
    // char a[10];
    // std::cin.get(a, 20);
    // std::cout << a << std::endl;

    // 2. 输入串长 < size，输入串长 < arraylength
    // 把串全部输入，后面补 '\0'
    char c[5];
    std::cin.get(c, 19);
    std::cout << c << std::endl;
    
    int i;
    char e[10];
    std::cin.get(e, 8, ',');
    std::cout << e << std::endl;

    return 0;
}