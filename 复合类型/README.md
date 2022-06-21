## 4.1 数组
声明数组: `typeName arrayName[arraySize];`

## 4.2 字符串
*C* 风格的字符串具有一种特殊的性质：以空字符串 （*null character*）结尾，空字符被写作 *\0* ，其 *ASCII* 码为 0，用来标记字符串的结尾。
```cpp
char dog[5] = {'b', 'e', 'a', 'u', 'x'}; // not a string
char dog[5] = {'b', 'e', 'a', 'u', '\0'}; // a string
```

#### 4.2.1 拼接字符串常量
```cpp
cout << "hello " "world" << endl;
```

#### 4.2.2 在数组中使用字符串
*sizeof* 指出的是整个数组的字节数
*strlen* 指出的是可见的字符，而不把空字符串计算在内

#### 4.2.3 字符串输入

#### 4.2.4 读取一行字符串
*istream* 中的类（如 *cin*）提供了一些面向行的类成员函数：*getline()* 和 *get()* ，两者都可以读取一行都数据，但是 *getline()* 会丢掉换行符，而 *get()* 不会丢掉换行符。
1. 面向行的输入： *getline()*
2. 面向行的输入：*get()*
```cpp
cin.get(name, ArSize);
cin.get(dessert, ArSize); // a problem
```
由于第一次调用后，换行符将留在输入队列中，因此第二次调用时看到的第一个字符便是换行符。
正确做法：
```cpp
cin.get(name, ArSize);
cin.get();
cin.get(dessert, ArSize);
```
3. 空行和其他问题

#### 4.2.5 混合输入字符串和数字
*numstr.cc* 中，用户根本没有输入地址的机会。问题在于，当 *cin* 读取年份的时候，将回车键换成换行符留在了输入队列中。后面的 *cin.getline()* 看到换行符后，将认为这是一个空行，并将空字符串传给 *address* 数组。
解决方案：
```cpp
cin >> year;
cin.get(); // or cin.get(ch)

// 也可以使用
(cin >> year).get();
```

## 4.3 *string* 类简介

#### 4.3.1 赋值、拼接和附加
初始化
```cpp
char charr1[20];
char charr2[20] = "jaguar";
string str1;
string str2 = "panther";
```
字符串拼接
```cpp
string str3;
str3 = str1 + str2;
str1 += str2;
```

#### 4.3.2 *string* 类的其他操作
*cstring* 中提供拼接函数 *strcat* 和 复制函数 *strcpy*  


#### 4.3.3 *string* 类 *IO*
*stringtype4.cc*
在用户输入之前，该程序指出数组 *charr* 的字符串的长度为 6，比该数组的长度还要大。这里有两点说明：
1. 未初始化的数组的内容是未定义的
2. 函数 *strlen* 从数组的第一个字节开始计数，直到遇到空字符

## 4.4 结构简介

#### 4.4.1 在程序中使用结构

#### 4.4.2 结构可以将 *string* 类作为成员吗 

#### 4.4.3 其他结构属性
成员赋值是有效的。
可以同时完成创建结构和初始化变量。
```cpp
struct perks {
    int key_number;
    char car[12];
}mr_smith, ms_jones;

struct perks {
    int key_number;
    char car[12];
}mr_qlitz = {
    7,
    "Pasdjk",    
};
```

#### 4.4.4 结构数组
```cpp
inflatable gift[100];
```

#### 4.4.5 结构中的位字段
与 *C* 语言一样，*C++* 允许制定占用特定位数的结构成员，这使得创建与某个硬件设备上的寄存器对应对数据结构非常方便。
```cpp
struct torgle_register
{
    unsigned int SN: 4;
    unsigned int: 4;
    bool goodIn: 1;
    bool goodTorgle: 1;
};
```

## 4.5 共用体
共用体 *union* 是一种数据结构，它能够存储不同类型的数据结构，但是只能存储其中的一种数据结构。也就是说，结构可以同时存储 *int*、*double* 和 *long* ，共用体只能存储 *int*、*double* 或 *long* 
```cpp
union one4all
{
    int int_val;
    long long_val;
    double double_val;
};
```
可以使用 *one4all* 变量来存储 *int*、*double*、*long* ，条件是在不同的时间进行：
```cpp
one4all pail;
pail.int_val = 15; // store an int
cout << pail.int_val;
pail.double_val = 1.38; // store a double, int value is lost
cout << pail.double_val;
```
共用体的长度为其最大最大成员的长度。

共用体的用途之一是，当数据项使用两种或更多格式时，可节省空间。例如，假设管理一个小商品目录，其中一些商品的 ID 为整数，而另一些的为字符串。
```cpp
struct widget
{
    char brand[20];
    int type;
    union id
    {
        long id_num;
        char id_char[20];
    } id_val;
};

widget prize;
if (prize.type == 1) {
    cin >> prize.id.id_num;
} else {
    cin >> prize.id.id_char;
}
```

匿名共用体没有名称，其成员将成为位于相同地址处的变量。
```cpp
struct widget
{
    char brand[20];
    int type;

    union
    {
        long id_num;
        char id_char;
    };
};

widget prize;
if (prize.type == 1) {
    cin >> prize.id_num;
} else {
    cin >> prize.id_char;
}
```
由于共用体时匿名的，yinci *id_num* 和 *id_char* 被视为 *prize* 的两个成员，它们的地址相同，所以不需要中间标志符 *id_val*。

## 4.6 枚举 
*C++* 提供了另外一种创建符号常量的方式，这种方式可以代替 *const*。它还允许定义新类型，但必须按照严格的限制进行。
```cpp
enum spectrum {
    red, orange, yellow, green, blue, violet,
    indigo
};
```

这条语句完成两个工作：
- 让 *spectrum* 成为一个新类型的名称：*spectrum* 被称为枚举（*enumeration*），就像 *struct* 变量被称为结构一样
- 将 *red*、*orange*、*yellow* 等作为符号常量，它们对应的整数值为 *0～6* 
可以使用枚举名来声明这种类型变量：
```cpp
spectrum band; // band a variable of type spectrum
```

```cpp
band = blue; // valid blue is an enumerator
band = 2000;
```

对于枚举类型，只定义了赋值操作符，没有为枚举定义赋值运算。
```cpp
band = orange;
++band; // not valid, ++ discussed in Charpter 5
band = orange + red; // not valid, but a little tricky
```

枚举量是整型，可被提升为 *int* 类型，但 *int* 类型无法自动转换为枚举类型
```cpp
int color = blue; // valid, spectrum type promoted to int
band = 3; // invalid, int not convert to spectrum
color = 3 + red; // valid, red convert to int
```

#### 4.6.1 设置枚举类型的值
可以使用赋值操作符显式的设置枚举量的值。
```cpp
enum bits {
    one = 1,
    two = 2,
    four = 4,
    eight = 8
};
```

```cpp
enum bigstep {
    first,
    second = 100;
    third
};
```
*first* 没有指定，默认情况下为 0，后面没有初始化的枚举量将比前面的枚举量大 1.

#### 4.6.2 枚举的取值范围
每个枚举都有取值范围，通过强制类型，可以将取值范围中的任何整数值赋值给枚举变量，即使这个值不是枚举变量。
```cpp
enum bits {
    one = 1,
    two = 2,
    four = 4,
    eight = 8
};
```
则下面的代码是合法的:
```cpp
myflag = bits(6);
```
其中 6 不是枚举值，但它位于枚举定义的取值范围内。

## 4.7 指针和自由存储空间 
计算机存储数据必须要跟踪的三个基本属性：
- 信息存储在何方
- 存储的值为多少
- 存储的信息是什么类型 

#### 指针与 *CPP* 基本原理
面向对象编程与传统的过程性编程的区别是，*OOP* 强调的是在运行阶段进行决策。运行阶段指的是程序正在运行时，编译阶段指的是

#### 4.7.1 声明和初始化指针
*char* 类型的指针和 *double* 类型的指针没有什么不同，但是 *char* 类型和 *double* 类型的字节数是不同的。

#### 4.7.2 指针的危险
在 *C++* 中创建指针时，计算机将分配用来存储地址的内存，但不会分配指针所指向数据的内存。

#### 4.7.3 指针和数字
指针不是整型，虽然计算机把地址当�进行处理。从概念上看，指针和整数是完全不同的类型。


#### 4.7.4 使用 *new* 来进行分配内存
我们将指针初始化为变量的地址：变量是在编译的时候进行分配内存的，而指针只是为了可以通过名称直接访问内存提供了一个别名。

```cpp
int *pn = new int;
```

*new int* 告诉程序，需要合适存储 *int* 的内存。*new* 操作符根据类型来确定需要多少字节内存。然后，它找到这样的内存并返回地址。

*use_new.cc* 程序说明
该程序使用 *new* 和 *double* 类型的数据对象分配内存。这是在程序运行时进行的。指针 *pt* 和 *pd* 指向这两个数据对象，如果没有它们，将无法访问这些内存单元。

#### 内存被耗尽 
计算机可能会由于没有足够的内存而无法满足 *new* 的请求。在这种情况下 *new* 将返回 *0*。在 *C++* 中，值为 *0* 的指针被称为空指针。*C++* 保证空指针不会指向有效的数据，因此它常用来表示操作符或函数失效。

#### 4.7.5 用 *delete* 来释放内存
*C++* 可以使用 *new* 来申请内存，当内存使用完成时，可以通过使用 *delete* 操作符来将内存归还到内存池。

```cpp
int *ps = new int; // allocate memory with new
delete ps; // free memory with delete when done
```

这将释放 *ps* 指向的内存，但不会删除指针 *ps* 本身。例如，可以将 *ps* 指向另外一个新分配的内存块。
内存泄漏：被分配的内存再也无法使用了。

不要尝试释放已经释放的内存块，*C++标准* 指出，这样做的结果是不确定的，这意味着什么都有可能发生。另外不能使用 *delete* 来释放声明的变量。    
```cpp
int *ps = new int; // ok
delete ps; // ok
delete ps; // not ok now
int jugs = 5; // ok
int *pi = &jugs; // ok
delete pi; // not allowed, memory not allocated by new
```

**警告：只能用 delete 来释放 new 分配的内存。不过对空指针使用 delete 是安全的**

#### 4.7.6 使用 *new* 来创建动态数组
静态联编：在编译时给数组分配内存，意味着数组是在编译时加入到程序的
动态联编：数组是在运行时创建的

1. 使用 *new* 创建动态数组
example:
```cpp
int *psome = new int[10]; // get a block of 10 ints
// 释放内存
delete []psome;
```
方括号告诉程序，应释放整个数组，而不仅仅是指针指向的元素。如果使用 *new* 时不带方括号，则使用 *delete* 时也不带上方括号。如果使用 *new* 时候带着方括号，则使用 *delete* 时也需要带上方括号。    

```cpp
int *pt = new int;
short *ps = new short[500];
delete []pt; // effect is undefined, don't do it
delete ps; // effect is undefined, don't do it  
```

总结：  
- 不要使用 *delete* 来释放不是 *new* 分配的内存
- 不要使用 *delete* 来释放内存两次
- 如果使用 *new []* 为数组分配内存，则应使用 *delete []* 来释放内存
- 如果使用 *new []* 为一个实体分配内存，则应使用 *delete* 来释放
- 对空指针使用 *delete* 来说是安全的    

2. 使用动态数组
```cpp
int *psome = new int[10]; // get a block of 10 ints
```

## 4.8 指针、数组和指针算数

#### 4.8.2 指针和字符串
```cpp
char flower[10] = "rose";
cout << flower << "s are red\n";
```

#### 4.8.3 使用 *new* 创建动态结构
在运行时创建数组优于在编译时创建数组，对于结构也是如此。需要在程序运行时为结构分配所需的空间，这也可以使用 *new* 操作符完成。

1. 一个使用 *new* 和 *delete* 的例子
程序 *delete.cc* 

2. 程序说明
它使用 *cin* 将输入的单词放到 *temp* 数组中，然后使用 *new* 进行分配内存，以存储该单词。程序需要 *strlen(temp) + 1* 个字符（包括空字符）来存储该字符串，因此将这个值提供给 *new* 。获得该空间后，`getname()` 使用标准库函数 *strcpy* 

#### 4.8.3 自动存储、静态存储和动态存储
1. 自动存储
在函数内部定义常规变量使用自动存储空间，被称为自动变量。实际上，自动变量是一个局部变量，其作用域为包含它的代码块。
2. 静态存储
静态存储是整个程序执行期间都存在的存储方式。是变量称为静态的方式有两种：一种是在函数外面定义它；另外一种是在声明变量的时候使用关键字 *static*
`static double fee = 56.50;`
3. 动态存储
*new* 和 *delete* 操作符提供了一种比自动变量和静态变量更灵活的方式。