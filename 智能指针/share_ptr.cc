// introduction

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
        std::shared_ptr<Test> sptr = std::make_shared<Test>(2);
        assert(sptr.use_count() == 1);  // 此时引用计数为 1
        {   
            std::shared_ptr<Test> sptr1 = sptr;
            assert(sptr.get() == sptr1.get());
            assert(sptr.use_count() == 2);   // sptr 和 sptr1 共享资源，引用计数为 2
        }   
        assert(sptr.use_count() == 1);   // sptr1 已经释放
    }
    // use_count 为 0 时自动释放内存

    std::cout << "In the end" << std::endl;

   return 0;
}