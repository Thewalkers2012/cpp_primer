#include <iostream>
#include <cstring>

struct Person
{
    // 职工基本信息的结构
    double salary;
    char *name;
};

class SalaryManage
{
private:
    Person *employ; // 存放职工信息的数组
    int max; // 数组下标上界
    int n; // 数组中的实际职工人数

public:
    SalaryManage(int Max = 0)
    {
        max = Max;
        n = 0;
        employ = new Person[max];
    }

    // 返回引用特性是可以直接放在左值，直接使用
    double &operator[](char *Name)
    {
        // 重载 []，返回引用
        Person *p;
        for (p = employ; p < employ + n; p++)
        {
            if (strcmp(p->name, Name) == 0)
                return p->salary;
        }

        // 不存在情况
        p = employ + n++;
        p->name = new char[strlen(Name) + 1];
        strcpy(p->name, Name);
        p->salary = 0;

        return p->salary;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << employ[i].name << " "
                << employ[i].salary << std::endl;
        }
    }

    ~SalaryManage()
    {
        delete []employ;
    }

};

int main()
{
    SalaryManage s(3);
    s["bob"] = 2188.88;
    s["alice"] = 2188.88;
    s["jack"] = 2188.88;

    std::cout << "bob\t" << s["bob"] << std::endl;
    std::cout << "alice\t" << s["alice"] << std::endl;
    std::cout << "jack\t" << s["jack"] << std::endl;

    std::cout << "now is time to display" << std::endl;
    s.display();

    return 0;
}