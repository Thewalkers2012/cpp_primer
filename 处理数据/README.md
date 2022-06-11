## 3.1 简单变量

#### 3.1.1 变量名
- 在名称中只能使用字符字母、数字和下划线
- 名称的第一个字符不能是数字
- 区分大写字符和小写字符
- 不能将 *C++* 关键字作为名称
- 以两个下划线或下划线和大写字母打头的名称被保留给实现使用。以一个下划线开头的名称被保留给实现，用作全局标志符
- *C++* 对于名称的长度没有限制，名称中所有字符都有意义

#### 3.1.2 整型
基本整型变量：*char*、*short*、*int*、*long* ，其中每种类型都有符号版本和无符号版本。

#### 3.1.3 *short*、*int* 和 *long*
- *short* 至少 16 位
- *int* 至少与 *short* 一样长
- *long* 至少 32 位，且至少与 *int* 一样长

```cpp
#include <iostream>
#include <climits>

int main() {
    using namespace std;

    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "int is" << sizeof(int) << " bytes." << endl;
    cout << "short is" << sizeof(int) << " bytes." << endl;
    cout << "long is" << sizeof(long) << " bytes." << endl;

    return 0;
}
```

#### climits 常用常量
| 符号常量 | 表示 |
| ---- | ---- |
| CHAR_BIT | char 的位数 |
| CHAR_MAX | char 的最大值 |
| CHAR_MIN | char 的最小值 | 
| SCHAR_MAX | signed char 的最大值 |
| SCHAR_MIN | signed char 的最小值 |
| UCHAR_MAX | unsigned char 的最大值 | 
| SHRT_MAX | short 的最大值 | 
| SHRT_MIN | short 的最小值 | 
| USHRT_MAX | unsigned short 最大值 |
| INT_MAX | int 最大值 | 
| INT_MIN | int 最小值 | 
| UNIT_MAX | unsigned int 的最大值 |
| LONG_MAX | long 的最大值 | 
| LONG_MIN | long 的最小值 |
| ULONG_MAX | unsigned long 的最大值 |

#### #define 的作用
define 编译指令的工作方式与文本编辑器或字处理器中的全局搜索和替换命令相似。

#### 3.1.4 无符号类型

#### 3.1.5 选择整型类型

#### 3.1.6 整型常量
整型常量是显示的书写的常量，如 212 或 1776。与 *C* 相同，*C++* 能够以 3 种不同的计数方式来书写整型：基数为 10，基数为 8，基数为 16。

```cpp
#include <iostream>

int main() {
    using namespace std;

    int chest = 42;
    int waist = 0x42;
    int inseam = 042;

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << "\n";
    cout << "waist = " << waist << "\n";
    cout << "inseam = " << inseam << "\n";

    return 0;
}
```

#### 3.1.7 *C++* 如何确定常量类型
```cpp
cout << "Year = " << 1492 << "\n";
```
程序将 1492 存储为 *int*、*long* 还是其他类型呢？
除非有理由存储为其他类型（如使用特殊后缀来表示特定类型，或者值太大不能存储为 *int*），否则 *C++* 将整型变量存储为 *int*

整数后面的 *l* 或 *L* 表示该整型为 *long* 常量，*u* 或 *U* 后缀表示 *unsigned int* 常量，*ul* 表示 *unsigned long* 常量，注意 *UL* 或 *LU* 都被存储为 *unsigned long* 型变量。

#### 3.1.8 *char* 类型：字符和小整数
*char* 类型是专门为了存储字符用的而设计的。
```cpp
#include <iostream>

int main() {
    using namespace std;
    char ch;

    cout << "Enter a character: " << endl;
    cin >> ch;
    cout << "Holla! ";
    cout << "Thank you for the " << " character." << endl;

    return 0;
}
```
1. `cout.put()` 是一个重要的 *OOP* 概念
2. 特殊字符
- 换行符：\n
- 水平制表符：\t
- 垂直制表符：\v
- 退格：\b
- 回车：\r
- 振铃：\a
- 反斜杠：\
- 问号：\?
- 单引号：\'
- 双引号：\"

3. 通用字符名称
*C++* 实现支持一个基本的源字符集，即可以用来编写代码的源字符集。它由大小写字符和、*C* 语言使用的符号(如{)和一些其他的符号(如换行符和空格)组成。
*C++* 还提供了扩展字符和扩展字符集。

通用字符名的用法类似于转义序列。通用字符名可以以 */u* 或 */U* 打头。*\u* 后面是 8 个十六进制位，*\U* 后面是 16 个十六进制位。这些字符表示的是字符的 *ISO 10646* 编码。

4. *signed char* 和 *unsigned char*
与 *int* 不同的是，*char* 在默认的情况下既不是有符号，也不是无符号的。

*unsigned char* 的范围在 0-255, *signed char* 的范围在 *-128～127* 。假设要使用一个 *char* 类型来存储一个 200 这样大的值，在某些系统是可以的，但是在另外一些系统又是不可以的。

5. *wchar_t*  
程序处理的字符集可能无法用一个 *8* 位的字节表示。首先，如果大型字符集实现的是基本字符集，则编译器厂商可以将 *char* 定义为 16 位或者更长的字符，其次另外一种实现可以支持小型字符集和较大的扩展字符集。*8* 位的 *char* 类型可以支持小型字符集，而 *wchar_t* 可以表示扩展字符集。

*cin* 和 *cout* 将输入输出看作是 *char* 流，因此不适合处理 *wchar_t* 类型。*iostream* 提供了 *wcin* 和 *wcout* 可以用来处理 *wchar_t* 流。另外可以通过前缀 *L* 来表示宽字符常量和宽字符串。
```cpp
wchar_t bob = L'P';
wcout << L"tall" << endl;
```


#### 3.1.9 新的 *bool* 类型

## 3.2 *const* 限定符
*const* 相比于 *define* 的优势
1. 它能够明确的指明类型
2. 可以使用 *C++* 的作用域规则将其限定在特定的函数或者文件中
3. 可以将 *const* 用于更复杂的类型

## 3.3 浮点数

#### 3.3.1 书写浮点数
第一种是标准的小数点表示法：
```cpp
12.34 // floating-point
8.0 
```

第二种表示浮点值的方法为 *E* 表示法：
其外观是这样的 *3.45E6* ，这里指的是 *3.45* 与 *1000000* 相乘的结果。

#### 3.3.2 浮点类型
*C++* 有三种浮点类型：*float*、*double* 和 *long double* 。

#### 3.3.3 浮点常量
```cpp
1.234f // a float constant
2.45E20f // a float constant
2.345324E28 // a double constant
2.2L // a long double constant
```
像 8.24 和 2.4E8 这样的浮点常量都属于 *double* 类型。如果想要使用 *float* 类型需要加上 *f* 或 *F* 后缀，对于 *long double* 类型，可以使用 *l* 或 *L* 后缀。

#### 3.3.4 浮点数的优缺点
浮点数的计算比整形的计算更慢。

## 3.4 C++ 算术操作符

#### 3.4.1 操作符的优先级和结合性
从左到右原则    

#### 3.4.2 除法分支
如果相除的两个数都是整数的话，那么小数部分将会被舍弃。
如果两个只要有一个是浮点数，那么结果就是浮点数。

#### 3.4.3 求模运算符

#### 3.4.4 类型转化
两个 *short* 值相加涉及到的硬件编译指令可能会与两个 *long* 值相加不同。

- 将一种算术类型的值赋给另一种算数类型的变量时，*C++* 将对值进行转换
- 表达式中包含不同类型的值时，*C++* 将对值进行转换。
- 将参数传递给函数时，*C++* 将对值进行转换。

1. 赋值时进行转换
例如 *so_long* 是一个 *long* 类型的变量，*thirty* 的类型是 *short* ，而程序中包含这样的语句，`so_long = thirty`，程序将 *thirty* （通常是 16 位）扩展为一个 *long* 值（通常是 32 位）。扩展后得到一个新的值，这个值存储在 *so_long* 中，而 *thirty* 的值不会变。 
- *double* 转换为 *double* 类型变量，精度降低，值可能超出目标类型的取值范围。
_ 小数类型转换为整形变量，小数部分丢失。
- 将较大的整形变量转换为较小的整形变量，如 *long* 转换为 *short* ，原来的值可能已经超出了目标值的取值范围，通常只复制右边的字节。
2. 表达式中的转换
```cpp
short chickens = 20;
short ducks = 35;
short fowl = chickens + ducks;
```
*CPP* 程序取得 *chickens* 和 *ducks* 的值之后，并将它们转换为 *int*，然后程序将结果转换为 *short* 类型。
当两种类型变量进行数值计算的时候，较小的类型会转换为较大的类型。
3. 传递参数时的转换
4. 强制类型转换
```cpp
type(value)
(type)value
```
第一种方式来自于 *C* 语言，第二种方式来自于 *CPP* 。新格式的想法就是让强制类型转换就像函数调用一样，这样对内置类型的强制类型转换就像是为用户定义的类设计的类型转换。



