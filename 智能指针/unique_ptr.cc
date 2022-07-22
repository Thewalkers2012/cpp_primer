// introduction
// 可以使用 unique_ptr 对资源进行管理，离开作用域后自动
// 释放资源

#include <iostream>

class Test {
public:
    Test(int value) {
        this->value = value;
        std::cout << "Test has been created, value = " 
            << value << std::endl;
    }

    ~Test() {
        std::cout << "Test has been destroyed, value = " 
            << value << std::endl;
    }

private:
    int value;
};

int main() {
    {
        std::unique_ptr<Test> uptr = std::make_unique<Test>(100);
    } 

    // unique ptr 可以指向一个数组
   {
        std::unique_ptr<int[]> uptr = std::make_unique<int[]>(10);
        for (int i = 0; i < 10; i++) {
            uptr[i] = i * i;
        }   
        for (int i = 0; i < 10; i++) {
            std::cout << uptr[i] << std::endl;
        }   
    }

   std::cout << "In the end" << std::endl;

   return 0;
}