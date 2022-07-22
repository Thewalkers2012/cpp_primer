#include "threadPool.h"
#include <string>
using namespace std;
class Task
{
private:
    int total = 0;
 
public:
    void process();
};
 
//任务具体实现什么功能，由这个函数实现
void Task::process()
{
    //这里就输出一个字符串
    cout << "task successful! " << endl;
    std::cout << "in thread #" << std::this_thread::get_id() << std::endl;
    this_thread::sleep_for(chrono::milliseconds(10));
}
 
template class std::queue<Task>;
int main(void)
{
    threadPool<Task> pool(10);
    while (1)
    {
        Task *task = new Task();
        pool.append(task);
        delete task;
    }
}
