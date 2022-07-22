// std::weak_ptr 要与 std::shared_ptr 一起使用。
// 一个 std::weak_ptr 对象看做是 std::shared_ptr 
// 对象管理的资源的观察者，它不影响共享资源的生命周期：
#include <iostream>

void Observe(std::weak_ptr<int> wptr) {
    if (auto sptr = wptr.lock()) {
        std::cout << "value: " << *sptr << std::endl;
    } else {
        std::cout << "wptr lock fail" << std::endl;
    }
}

int main()
{
    std::weak_ptr<int> wptr;
    {
        auto sptr = std::make_shared<int>(111);
        wptr = sptr;
        Observe(wptr);  // sptr 指向的资源没被释放，wptr 可以成功提升为 shared_ptr
    }
    Observe(wptr);

    return 0;
}