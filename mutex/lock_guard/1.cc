#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex mt;

void thread_task()
{
    for (int i = 0; i < 10; i++)
    {
        std::lock_guard<std::mutex> guard(mt);
        std::cout << "print thread: " << i << std::endl;
    }
}

int main()
{
    std::thread t(thread_task);

    for (int i = 0; i > -10; i--)
    {
        std::lock_guard<std::mutex> guard(mt);
        std::cout << "print main: " << i << std::endl;
    }

    t.join();

    return 0;
}