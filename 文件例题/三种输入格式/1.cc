#include <iostream>

int main()
{
    char a, b, c, d;
    std::cin.get(a);
    std::cin.get(b);

    c = std::cin.get();
    d = std::cin.get();

    std::cout << int(a) << "," << int(b)
        << "," << int(c) << "," <<
        int(d) << std::endl;

    return 0;
}