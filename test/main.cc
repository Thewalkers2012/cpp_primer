#include <vector>
#include <iostream>
#include <string>

class Solution 
{
private:
    int m_int;
    double m_double;
    std::string m_string;

public:
    Solution(int x, double y, std::string s) : m_int(x) 
    {
        m_double = y;
        m_string = s;
    }

    void print()
    {
        std::cout << "id: " << m_int << std::endl;
        std::cout << "double value: " << m_double << std::endl;
        std::cout << "string value: " << m_string << std::endl;
    }
};

int main()
{
    std::vector<Solution> v;
    v.emplace_back(1, 2.89, "a");
    v.emplace_back(2, 23.43, "b");

    for (auto &x: v)
    {
        x.print();
    }
}