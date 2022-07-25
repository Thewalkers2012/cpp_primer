#include <iostream>

int main()
{
    char stu[5][10];

    for (int i = 0; i < 5; i++)
    {
        std::cin.getline(stu[i], 10, ',');
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << stu[i] << std::endl;
    }

    return 0;
}