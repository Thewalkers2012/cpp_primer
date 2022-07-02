## 9.1 单独编译
头文件常包含的内容
- 函数原型
- 使用 *define* 和 *const* 定义的符号常量
- 结构声明
- 类声明
- 模版声明
- 类声明

将结构声明放在头文件中是可行的，因为它们并不创建变量，而只是在源代码文件中声明结构变量时，告诉编译器如何创建该结构变量。同样，模版声明不是将被编译的代码，它们指示编译器如何生成与源代码相匹配的函数定义。被声明为 *const* 的数据和内联函数有特殊的链接属性。

头文件管理  
在同一个文件中只能将同一个头文件包含一次。编译器首次遇到该文件的时候，名称 *COORDIN_H_* 没有定义（我们根据 *include* 文件名来选择名称，并加上一些下划线，以创建一个在其他地方不太可能被定义的名称）。在这种情况下，编译器将查看 *#ifndef* 和 *#endif* 之间的内容（这正是我们希望的），并读取定义 *COORDIN_H* 的一行。如果在同一文件中遇到其他包含 *coordin.h* 的代码，编译器将知道 *COORDIN_H* 已经被定义，从而跳到 *#endif* 后面的一行上面去。这种方式并不能够防止编译器将头文件包含两次，而只是让它忽略除第一次包含之外的所有内容。

## 9.2 存储持续性、作用域和链接性
*C++* 用三种不同的方式来存储数据，这些方案的区别就在于数据保留在内存中的时间

- 自动存储持续性：在函数定义中声明的变量（包括函数参数）的存储持续性是自动的。它们在程序开始执行其所属的函数或代码块时被创建，在执行完函数或代码块时，它们使用的内存被释放。*C++* 有两种存储持续性为自动的变量。
- 静态存储持续性：在函数定义外定义的变量和使用关键字 *static* 定义的变量的存储持续性都为静态。它们在程序整个运行过程中都存在。*C++* 有三种存储持续性为静态的变量。
- 动态存储持续性：用 *new* 操作符分配的内存将一直存在，知道 *delete* 将其释放或程序结束为止。

#### 9.2.1 作用域和链接

#### 9.2.2 自动存储持续性
1. 自动变量的初始化
可以使用任何在声明时其值为已知的表达式来初始化自动变量
```cpp
int w;
int x = 5;
int y = x * 2;
cin >> w;
int z = 3 * w;
```
2. 自动变量和堆栈
3. 寄存器变量
如果变量被存储在 *register* 中，则没有内存地址，因此不能将地址操作符用于寄存器变量。在下面的例子中，获取 *x* 的地址是可行的，但是获取 *y* 的地址是不可行的。
```cpp
void gromb(int *);

int main() {
    int x;
    register y;

    gromb(&x);
    goomb(&y);
}
```

#### 9.2.3 静态持续变量
三种链接性：外部链接性、内部链接性和无链接性
```cpp
int global = 1000;
static int one_file = 50;

int main() {
    ...
}

void func1(int n) {
    static int count = 0;
    int llama = 0;
}

void func2(int q) {

}
```

正如前面指出的，所有的静态持续变量（上述范例中的 *global* 、*one_file* 和 *count*）在整个程序执行期间都存在。在 *func1* 中声明的变量 *count* 的作用域是局部的，没有链接性，这意味着只能在 *func1* 中使用它，就像 *llama* 变量一样。但是，与 *llama* 变量不同的是，即使 *func1* 函数没有执行，*count* 也留在内存中。*global* 和 *one_file* 的作用域为整个文件，即在从声明位置到文件结尾的范围内都可以被使用。具体到说，在 *main*，*func1*，*func2* 中使用它们。由于 *one_file* 的链接性是内部的，因此只能在包含上述代码的文件中使用它。由于 *global* 的链接为外部的，因此可以在程序的其他文件中使用它。

所有静态持续变量都有以下两个初始化特征:
- 未被初始化的静态变量的所有位都被设置为 0
- 只能使用常量表达式来初始化静态变量

#### 9.2.4 说明符和限定符
下面是存储说明符：
- auto
- register
- static
- extern
- mutable
下面是 *cv* 限定符
- const
- volatile

*volatile* 关键字表明，即使程序代码没有对内存单元进行修改，其值也可能发生变化。该关键字的作用为改善编译器的优化能力，例如：假设编译器发现，程序在几条语句中两次使用某个变量的值，则编译器可能不是让程序查这个值两次，而是将这个值缓存到寄存器中。声明为 *volatile* 则表示不进行这种优化。

*mutable* 指出即使结构为 *const*，其某个成员也可以被修改。

#### 9.2.5 函数链接性

和 *C* 语言一样，*C++* 不允许在一个函数中定义另一个函数，因此所有函数的存储持续性都自动为静态的，即在整个程序的运行过程中都是存在的。在默认情况下函数的链接性为外部的，即可以在各个文件中进行共享。实际上，可以通过 *extern* 来指出函数是在另一个文件中定义的，不过这个是可选的（要让程序在另一个文件中查找函数，该文件必须作为程序的组成部分进行编译，或者是由链接程序搜索的库文件）。还可以使用关键字 *static* 将函数的链接性设置为内部的，使之只能在一个文件中使用。
```cpp
static int private(double x);

...
static int private(double)
{

}
```

这意味着该函数只在这一个文件中可见，还意味着可以在其他的文件中定义同名的函数。和变量一样，在定义静态函数文件中，静态函数将覆盖外部定义，因此即使在外部定义了同名的函数，该函数仍将使用静态函数。    


#### 9.2.6 语言链接性   

另外一种链接性为语言链接性，也对函数有影响。链接程序要求每个不同的函数都有不同的符号名。在 *C* 语言中，一个名称对应一个函数，因此这很容易实现。为了满足内部需求，*C* 语言编译器可能将 *spiff* 这样的函数翻译为 *_spiff* 。这种方法被称为 *C* 语言链接性。但在 *C++* 中，同一名称可能对应多个函数，必须将这些函数翻译为不同的符号名称。因此，*Ç++* 编译器执行名称矫正或名称修饰，为重载函数修饰不同的符号名称。例如，可能将 *spiff(int)* 转换为 *_spoff_i* ，而将 *spiff(double, double)* 转换为 *_spiff_d_d* 。这种方式被称为 *C++* 语言链接。

链接程序寻找与 *C++* 函数调用匹配的函数时，使用的方法是与 *C* 语言不同的。但如果在 *C++* 程序中使用 *C* 库中预编译的函数，将出现什么样的情况呢。例如，有下面的代码。

```cpp
spiff(22); // want spiff(int) from a C library
```

它在 *C* 库文件中的符号名称为 *_spiff*，但对于我们假设的链接程序来说，*C++* 查询约定是查找符号名称 *_spiff_i* 
```cpp
extern "C" void spiff(int); // use C protocol for name look-up 
extern void spoff(int); // use C++ protocol for name look-up
extern "C++" void spiff(int); // use C++ protocol for name look-up
```

#### 9.2.7 存储方案和动态分配

## 9.3 布局 *new* 操作符
关于 *newplace.cc* 的程序说明
布局 *new* 确实将数组 *p2* 放到了数组 *buffer* 中，*p2* 和 *buffer* 中的地址是相同的。同时，常规 *new* 操作符将数组 *p1* 放到了很远的地方，位于动态管理的堆中。

## 9.4 命名空间

#### 9.4.1 传统的 *C++* 命名空间

#### 9.4.2 新的名称空间特性
*C++* 新增了这样一种功能，即通过定义一种新的声明区域来创建命名的名称空间，这样做的目的之一是提供一个声明名称的区域。一个名称空间中的名称不会与另外一个名称空间的相同名称发生冲突，同时允许程序的其他部分使用该命名空间中声明的东西。

```cpp
namespace Jack {
    double pail; // variable declaration

    void fetch(); // function prototype

    int pal; // variable declaration

    struct Wall { 

    }; // structure declaration
};
```

```cpp
namespace Jill {
    double bucket(double n) { ... } // function definition

    double fetch; // variable declaration

    int pal; // variable declaration

    struct Hill { ... } // structure declaration
};
```

任何名称空间中的名字都不会与其他名称空间中的名字发生冲突。因此 *Jack* 中的 *fetch()* 可以与 *Jill* 中的 *fetch()* 共存，*Jill* 中的 *Hill* 可以与外部的 *Hill* 共存。

名称空间是开放的，即可以把名称加到已有的名称空间中。例如，
```cpp
namespace Jill {
    char *goose(const char*);
}
```
将名称 *goose* 添加到 *Jill* 已有的名称空间中。

需要一种方法来访问给定名称空间中的名称。最简单的方法是，通过作用域解析操作符 *::* ，使用名称空间来限定名称。
```cpp
Jack::pail = 12.34; // use a variable
Jill::Hill mole; // create a type Hill structure
Jack::fetch(); // use a function
```

未被装饰的名称（如 *pail*）被称为未限定名称（*unqualified name*）。包含名称空间的名称（如，*Jack::pail*）被称为限定的名称。

1. *using* 声明和 *using* 编译指令  

*using* 声明由被限定的名称和它前面的关键字 *using* 指定
```cpp
using Jill::fetch; // a using declaration
```
example:
```cpp
namespace Jill {
    double bucket(double n) { ... }

    double fetch; 

    struct Hill {

    }
}

char fetch;

int main() {
    using Jill::fetch;

    double fetch; // Error! Already have a local fetch

    cin >> fetch; // read a value into Jill::fetch

    cin >> ::fetch; // read a value into global fetch
}
```

*using* 声明使一个名称可用，而 *using* 编译指令使所有的名称都可用。*using* 编译指令由名称空间和它前面的关键字 *namespace* 组成，它使得名称空间中的所有名称都可用，而不需要使用作用域解析操作符。

2. *using* 编译指令和 *using* 声明之比较

3. 名称空间和其他特性

可以将命名空间声明进行嵌套
```cpp
namespace elements {
    namespace fire {
        int flame;
        ...
    }
    float water;
}
```

4. 未命名的名称空间 
可以通过省略名称空间的名称来创建未命名的名称空间
```cpp
namespace // unnamed namespace
{
    int ice;
    int bandycoot;
}
```
这就像后面跟着 *using* 编译指令一样，在该名称空间中声明的名称的潜在作用域为：从声明点到该声明区域末尾。从这个方面看，他们与全局变量相似。不过，由于这种名称空间没有名称，因此不能显示的使用 *using* 编译指令或 *using* 声明来使它在其他位置都可用。

#### 9.4.3 名称空间范例 

#### 9.4.4 名称空间及其前途
指导原则
- 使用在已命名的名称空间中声明的变量，而不是使用外部的全局变量  
- 使用在已命名的名称空间中声明的变量，而不是使用静态的全局变量
- 如果开发了一个函数库或者类库，将其放到一个名称空间里面
- 仅将编译指令 *using* 作为一种将旧代码转换为使用名称空间的权宜之计
- 不要在头文件中使用 *using* 编译指令
- 导入名称时，首选使用作用域解析操作符或 *using* 声明
- 对于 *using* 声明，首选将其作用域设置为局部而不是全局的




