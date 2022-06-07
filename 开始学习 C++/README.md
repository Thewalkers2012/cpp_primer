## 2.1 进入 C++

#### 2.1.1 *main* 函数
```cpp
int main() {
    statements;
    return 0;
}
```
1. 作为接口的函数头
很多现有的程序都采用经典的 C 函数头：`main()` (*original C stycle*)，在 *C* 语言中，省略返回类型相当于说函数的类型为 *int*。不过，*C++* 将逐渐淘汰这种用法，也可以使用下面的变体 `int main(void)`，在括号中使用关键字 *void* 明确指出，该函数不接受任何参数。在 *C++* 中，让括号空着和填写 *void* 是等价的。
2. 为什么 *main()* 不能使用其他名称
如果没有 *main* 函数程序将不完整，编译器将指出未定义*main()* 函数。存在一些特殊情况，在 *Windows* 编程中，可以编写一个动态链接库（DLL）模块，这是其他 *Windows* 程序可以使用的代码。由于 *DLL* 模块不是独立的程序，因此不需要 *main()* 函数。

#### 2.1.2 C++ 注释
C++ 注释以双斜杠（//）打头。注释是程序员为读者提供的说明，通常标志程序的一部分或解释代码的某方面。

#### 2.1.3 C++ 预处理器和 *iostream* 文件
编译指令导致处理器将 *iostream* 文件内容添加到程序中。这是一种典型的预处理器操作：在源代码被编译之前，替换或添加文本。

#### 2.1.4 头文件名
像 *iostream* 这样的文件叫做包含文件（include file）-- 由于它们被包含在文件起始处。*C++* 编译器自带了很多头文件，每个头文件都支持一组特定的工具。*C* 语言的传统是，头文件使用扩展名 *.h*，将其作为一种通过名称标志文件类型的简单方式。

#### 2.1.5 命名空间
`using namespace std;`
这叫做 `using` 编译指令（*directive*）。
命名空间支持是 *C++* 中比较新的特性，它是为了使编写将多个厂商已有的代码组合起来的程序更简单设计的。

#### 2.1.6 使用 *cout* 进行 *C++* 输出
1. 控制符 *endl*
*endl* 是一个特殊的 *C++* 符号，表示一个重要的概念：重启一行。在输出流中插入 *endl* 将导致屏幕光标移到下一行的开头。
2. 换行符
*\n*

#### 2.1.7 *C++* 源代码格式化
在 *C++* 中，分号标志语句的结束。

## C++ 语句

```cpp
#include <iostream>

int main() {
    using namespace std;

    int carrots;

    carrots = 25;

    cout << "I have";
    cout << carrots;
    cout << " carrots.";
    cout << endl;
    carrots = carrots - 1;
    cout << "Crunch, crunch. Now I have" << carrots << " carrots." << endl;

    return 0;
}
```

#### 2.2.1 声明语句和变量
要将信息存储在计算机中，必须指出信息的存储位置和所需的内存空间。在 *C++* 中，完成这种任务的一种相对简便的方式，是使用声明语句来指出存储类型并提供位置标签。

#### 2.2.2 赋值语句
下面语句是合法的
```cpp
int steinway;
int baldwin;
int yamaha;

yamaha = baldwin = steinway = 88;
```
赋值语句从右往左进行。首先 88 被赋值给 *steinway*；然后，*steinway* 的值被赋值给 *baldwin* ，然后 *baldwin* 的值 88 被赋值给 *yamaha*。

#### 2.2.3 *cout* 的新花样

## 2.3 其他 C++ 语句

#### 2.3.1 使用 *cin* 语句
与 *cout* 一样，*cin* 也是一个智能对象。它可以通过键盘输入一系列字符（即输入）转换为接收信息。

#### 2.3.2 使用 *cout* 进行拼接
`cout << "Now you have " << carrots << " carrots" << endl;`

#### 2.3.3 类简介

## 2.4 函数

#### 2.4.1 使用有返回值的函数
参数是发送给函数的信息，返回值是从函数发送回的信息。

#### 2.4.2 函数变体
有些函数需要多项信息。这些函数使用多个参数，参数间用逗号隔开。

#### 2.4.3 用户定义的函数
标准 C 库提供了 140 个预定的函数。
```cpp
#include <iostream>

void simon(int);

int main() {
    using namespace std;

    simon(3);
    cout << "Pick an integer: ";
    int count;
    cin >> count;
    simon(count);

    cout << "Done!" << endl;

    return 0;
}

void simon(int n) {
    using namespace std;

    cout << "Simon says touch your toes " << n << " times." << endl;
    // void function don't need return statement
}
```

#### 关键字
*C++* 关键字：*int*、*void*、*return*、*double*。

#### 2.4.4 用户定义的有返回值的函数
```cpp
#include <iostream>

int stonetolb(int);

int main() {
    using namespace std;

    int stone;
    cout << "Enter the weight in stone:";
    cin >> stone;

    int pounds = stonetolb(stone);
    cout << stone << " stone = ";
    cout << pounds << " pounds.";

    return 0;
}

int stonetolb(int sts) {
    return 14 * sts;
}
```

#### 2.4.5 在函数程序中使用 *using* 编译指令
```cpp
#include <iostream>
using namespace std;

void simon(int);

int main() {
    simon(3);

    cout << "Pick an integer: ";
    int count;
    cin >> count;

    simon(count);
    cout << "Done!" << endl;

    return 0;
}

void simon(int n) {
    cout << "Simon says touch your toes " << n << " times " << endl;
}
```

## 2.5 总结
- 声明语句：定义函数中使用的变量名称和类型
- 赋值语句：使用赋值操作符（=）给变量赋值
- 消息语句：将消息发送给对象，激发某种行为
- 函数调用：执行函数。被调用的函数执行完毕后，程序返回到函数语句调用后面的语句
- 函数原型：声明函数的返回类型、函数接受的参数数量和类型
- 返回语句：将一个值从被调用的函数哪里返回到调用函数中


