## 8.1 *C++* 内联函数

内联函数是 *C++* 为了提高程序运行速度所做的一个改进。常规函数和内联函数之间的主要区别不在于编写方式，而在于 *C++* 编译器如何将它们组合到程序中。

内联函数的编译代码与其他程序代码“内联”起来。也就是说，编译器将使用相应的函数代码来替换掉函数调用。对于内联代码，函数无需跳到另一个位置处执行代码，然后再跳回来。因此，内联函数的运行速度比常规函数稍快，但代价是消耗更多的内存。如果程序在 10 个不同地方调用同一个内联函数，则程序将包含该函数的 10 个代码拷贝。

使用方式：
- 在函数声明前加上关键字 *inline*
- 在函数定义时加上关键字 *inline*

## 8.2 引用变量

#### 8.2.1 创建引用变量
```cpp
int rats;
int &rodents = rats; // makes rodents an alias for rats
```
其中，& 不是去地址符，而是类型标志符的一部分。可以通过初始化声明来设置引用，但是不能通过赋值来设置。

#### 8.2.2 将引用作函数参数

#### 8.2.3 引用的属性和特别之处
临时变量、引用参数和 *const*
如果实参与引用参数不匹配，*C++* 将生成临时变量。仅当变量是 *const* 引用时，*C++* 才允许这样做，但这是一种新的限制。
首先，什么时候将创建临时变量呢？如果引用参数是 *const*，则编译器将在下面两种情况下生成临时变量。
- 实参的类型正确，但不是左值
- 实参的类型不正确，但是可以转换为正确类型

左值参数是可被引用的数据对象，例如，变量、数组元素、结构成员、引用和被解除引用的指针都是左值。非左值包括字面常量和包含多项的表达式。例如，假如我们重新定义 *refcube()*，使之接受一个常量引用参数：
```cpp
double refcube(const double &ra) {
    return ra * ra * ra;
}
```

#### 8.2.4 将引用用于结构
引用非常适合结构和类。使用结构的方式和使用基本引用变量的方式相同，只需在声明结构参数时使用引用操作符 *&* 即可。

#### *strtref.cc* 程序说明
该程序尝试了三个领域：
1. 使用指向结构等引用，该函数将结构 *looper* 按引用传递给 *use* 函数，是得 *sysopref* 成为 *looper* 的别名。当函数 *use()* 显示 *sysopref* 的 *name* 和 *quote* 成员时，实际上显示是 *looper* 的成员。另外，当该函数将 *sysopref.used* 加 1 时，实际上是将 *looper.used* 加 1。 
2. 将引用作为返回值。通常，返回机制将返回值复制到临时存储区域中，随后调用程序访问该区域。然而返回引用意味着直接调用程序的返回值，而不需要进行拷贝。
`copycat = use(looper);`
如果 *use()* 返回的是一个结构，*sysopref* 的内容将被复制到一个临时返回存储单元中，然后该临时返回存储单元的内容将被复制到 *copycast* 中。然而，由于 *used()* 返回一个指向 *looper* 的引用，在这种情况下，*looper* 中的内容直接被赋值到 *copycast* 中。
3. 使用函数调用来访问结构的成员。
```cpp
cout << "use(looper): " << use(looper).used << "use(s)\n";
```
表示法 `use(looper).used` 访问的是 *looper* 的成员变量 *used*。如果该函数返回一个结构而不是指向结构的引用，则这些代码访问的将是 *looper* 的临时拷贝的 *used* 成员。

#### 返回引用所需要注意的问题
返回引用时重要的一点是，应避免返回函数终止时不再存在的内存单元引用，读者应避免编写如下代码。
```cpp
const sysop& clone2(sysop &sysopref) {
    sysop newguy;
    newguy = sysopref;
    return newguy;
}
```
同样也应当避免返回临时变量的指针。 

#### 为何将 *const* 用于引用返回类型
在前面的范例中，函数 *use()* 的返回类型为 *const sysop &*。读者可能会问，在这里的 *const* 有什么用。它并不意味着结构 *sysop* 本身为 *const*，而意味着您不能使用返回的引用来直接修改它指向的结构。如果省略了 *const* 就可以有以下写法。
```cpp
use(looper).used = 10;
```

#### 8.2.5 将引用用于类对象

将 *C* 风格字符串作 *string* 对象引用参数
对于函数 *version1()*，读者可能注意到一点：该函数的两个形参（*s1* 和 *s2*）类型都是 *const string&* ，但实参数（*input* 和 "***") 的类型分别是 *string* 和 *const char\** 该程序怎么能将 *char* 指针赋值给 *string* 引用呢。 
这里需要注意一点，就是 *string* 类型定义了一种从 *char* 指针到 *string* 类型转换的一种方式。这使得 *C* 风格字符串能够有一种从 *char* 指针转换到 *string*。其次是之前讨论的类型为 *const* 引用的形参的一个属性。假设实参的类型与引用参数类型不匹配，但是可以转换到引用类型，程序将创建一个正确类型的临时变量，使用转换后的实参值来初始化它，然后传递一个指向该临时变量的引用。

#### 8.2.6 对象、继承和引用
*ostream* 和 *ofstream* 类凸显了引用的一个属性。 *ofstream* 对象可以使用 *ostream* 类的方法，这使得文件输入/输出的格式与控制台输入/输出相同。
继承的另外一个特性就是：基类的引用可以指向一个派生类对象，而无需进行强制类型转换。这种特征的一个实际结果是，可以定义一个接受基类引用作为参数的函数，调用该函数时，可以将基类对象作为参数，也可以将派生类作为参数。

*filefunc.cc* 程序说明
对于程序最重要的一点是参数 *os* 可以指向 *ostream* 如(*cout*) 也可以指向 *fstream* 如(*fout*)。

*setf* 让你可以设置各种格式化状态。例如调用 *setf(ios_base::fixed)* 将对象置于定点表示法模式；*setf(ios_base::showpoint)* 将对象置于显示小数点模式，即使小数部分为 0。方法 *precision* 指定显示多少位小数。所有这些设置将一直保持不变，直到再次调用相应的方法重制它们。方法 *width* 设置下一次输出操作使用字段的宽度，这种设置只在下次显示什么值的时候有用，然后将恢复到默认设置。

函数 *filefunc.cc* 有两处有趣的方法调用：
```cpp
ios_base::fmtflags initial;
initial = os.setf(ios_base::fixed);
...
os.setf(initial);
```
方法 *setf()* 返回调用它之前有效的所有格式化设置。*ios_base::fmtflags* 是存储这类信息所需要的数据类型。因此，将返回赋给 *initial* 将存储调用 *file_it()* 之前的格式化设置，然后便可以使用变量 *initial* 作为参数来调用 *setf* ，将所有的格式化设置为原来的值。

#### 8.2.7 何时使用引用参数

## 8.3 默认参数
对于带参数列表的函数，必须从右向左添加默认值。也就是说，要为某个参数设置默认值，就必须为它右边的所有参数设置默认值。
```cpp
int harpo(int n, int m = 4, int j = 5); // VALID
int chico(int n, int m = 6, int j); // INVALID
int groucho(int k = 1, int m = 2, int n = 3); // VALID
```

## 8.4 函数重载
函数重载是指可以有多个同名的函数。函数重载的关键是函数的参数列表--也称为函数的特征标。如果两个函数的参数数目和类型相同，同时参数的排列顺序也相同，则它们的特征标相同，而变量名是无关紧要的。*C++* 允许定义名称相同的函数，条件是它们的特征标不同。
```cpp
void print(const char *str, int width); // #1
void print(double d, int width); // #2
void print(long l, int width); // #3
void print(int i, int width); // #4
void print(const char *str); // #5
```

使用被重载的函数时，需要在函数调用中使用正确的参数类型。例如，下面的语句
```cpp
unsigned int year = 3210;
print(year, 6);
```
*print()* 调用与哪个原型匹配呢？它与任何原型部匹配！没有匹配的原型并不会停止使用其中的某个函数，因为 *C++* 将尝试使用标准类型转换强制进行匹配。如果 #2 原型是 *print()* 唯一的原型，则函数调用 *print(year, 6)* 将把 *year* 转换为 *double* 类型。但在上面的代码中，有 3 个将数字作为第一个参数的原型，因此有 3 中转换 *year* 的方法。在这种情况下，*C++* 将拒绝这种函数调用，并将其视为错误。

一些看起来彼此不同的特征是不能共存的。
```cpp
double cube(double x);
double cube(double &x);
```
可能认为在此处使用了函数重载，因为它们的特征标看起来不同。假设有以下代码：
```cpp
cout << cube(x);
```
参数 x 与 *double x* 原型和 *double &x* 原型都匹配，因此编译器无法确认究竟使用了哪个。为了避免这种混乱，编译器将类型引用和类型本身视为同一特征标。

函数匹配时，并不区分 *const* 和非 *const* 变量
```cpp
void dribble(char *bits); // overloaded
void dribble(const char *bits); // overloaded
void dabble(char *bits); // not overloaded
void drivel(const char* bits); // not overloaded
```
下面列出了各种函数调用对应的原型：
```cpp
const char p1[20] = "How's the weather";
char p2[20] = "How's business?";
dribble(p1); // dribble(const char*);
dribble(p2); // dirbble(char *);
dabble(p1); // no match
dabble(p2); // dabble(char *)
drivel(p1); // drivel(const char *);
dribel(p2); // dirvel(const char *);
```

*dribble* 有两个函数原型，一个用 *const* 指针，一个用常规指针，编译器将根据实参是否为 *const* 来决定使用哪个原型。*dirbble()* 函数只与带非 *const* 参数的调用匹配，而 *drivel()* 函数可以与带 *const* 或非 *const* 参数的调用匹配。*dirvel()* 和 *dabble()* 之所以在行为上有差异，主要是由于将非 *const* 变量赋值给 *const* 变量是合法的，反之则不是合法的。

#### 8.4.1 重载范例

#### 8.4.2 何时使用函数重载

什么是名称修饰？
*C++* 编译器将执行一些神奇的操作--名称修饰（name decoration）或名称矫正（name mangling），它根据函数原型中指定的形参类型对每个函数名进行加密，请看下述未经修饰的函数原型
```cpp
long MyFunctionFoo(int, float);
```
这种格式对于我们人类来说很适用，我们知道函数接受两个参数（一个为 *int* 类型，另外一个为 *float* 类型），并返回一个 *long* 值，而编译器将名称转换为不太好看的内部表示，来描述该接口。
```cpp
?MyFunctionFoo@@YAXH@Z
```
对原始名称进行的表面看起来无意义的修饰（或矫正，因人而异）将参数数目和类型进行编码，添加的一组符号随函数特征标而异，而修饰时使用的约定随编码器而异。

## 8.5 函数模板 
函数模版允许以任意类型的方式来定义函数。
```cpp
template <class Any>
void Swap(Any &a, Any &b) {
    Any temp;
    temp = a;
    a = b;
    b = temp;
```
第一行指出，要建立一个模版，并将类型命名为 *Any*。关键字 *template* 和 *class* 是必须的，除非可以使用 *typename* 来代替 *class* 。*typename* 关键字使得参数 *Any* 表示类型这一点更加明显：不过，有大量的代码库是使用关键字 *class* 开发的。在这种上下文中，这两个关键字是等价的。

#### 8.5.1 重载的模版   
需要多个对不同类型使用同一算法的函数时，可使用模版。

#### 8.5.2 显示具体化
假设定义了如下结构：
```cpp
struct job {
    char name[40];
    double salary;
    int floor;
};
```
另外，假设希望能够交换这两个结构的内容。原来的模版使用下面的代码完成交换。
```cpp
temp = a;
a = b;
b = temp;
```
由于 *C++* 允许将一个结构赋值给另一个结构，因此即使 *Any* 是一个 *job* 结构，上述代码也适用。但是，假设只想交换 *salary* 和 *floor* 成员，而不交换 *name* 成员，则需要使用不同的代码，但 *Swap()* 的参数将保持不变，因此无法使用模版重载来提供其他代码。

1. 第三代具体化
- 对于给定的函数名，可以有非模版函数·模版函数和显式具体化模版函数以及它们的重载版本
- 显式具体化的原型和定义应以 *template<>* 打头，并通过名称来指出类型。
- 具体化将覆盖常规模版，而非模版函数将覆盖具体化和常规模版
```cpp
// non-template function prototype
void Swap(job &a, job &b);

// template prototype
template <class Any>
void Swap(Any &a, Any &b);

// explicit specialization for the job type
template<> void Swap<job>(job &a, job &b);
```
前面指出，如果有多个原型时，则编译器在选择原型时，非模版版本将优先于显示具体化和模版版本，而显示具体化将优先于使用模版生成版本。

2. 早期的具体化方案
将
```cpp
template<> void Swap<job>(job &j1, job &j2);
```
替换为
```cpp
void Swap(job &j1, job &j2);
```
并将
```cpp
template<> void Swap<job>(job &j1, job &j2) {
    ...
}
```
替换为
```cpp
void Swap(job &j1, job &j2) {
    ... // code unchange
}
```

#### 8.5.3 实例化和具体化

#### 8.5.4 编译器选择使用哪个函数版本
- 第 1 步，创建候选函数列表。其中包含与被调函数的名称相同的函数和模版函数。
- 第 2 步，使用候选函数列表创建可行函数列表。这些都是参数数目正确的函数，为此有一个隐式转换序列，其中包含实参类型与相应的形参类型完全匹配的情况。例如，使用 *float* 参数的函数调用可以将该参数转换为 *double* ，从而与 *double* 形参匹配，而模版可以为 *float* 生成一个实例。
- 第 3 步，确定是否有最佳的可行函数。如果有，则使用它，否则报错。

考虑只有一个函数参数的情况：
```cpp
may('B');
```
首先编译器将寻找候选者，即名称为 *may()* 的函数和函数模版。然后寻找那些可以用一个参数调用的函数。
```cpp
void may(int); // #1
float may(float, float = 3); // #2
void may(char); // #3
char* may(const char *); // #4
char may(const char &); // #5
template<class T> void may(const T &); // #6
template<class T> void may(T *); // #7
```

注意，只考虑特征标，而不考虑返回类型。其中的两个候选函数（#4 和 #7）不可行，因为整数类型不能隐式地转换为指针类型。剩余的一个模版可用来生成具体化，其中 T 被替换为 *char* 类型，这样剩下 5 个可行的函数，其中的每个函数，如果它是声明的唯一一个函数，都可以被使用。

接下来，编译器必须确定哪个可行函数是最佳的。它查看为使函数调用参数与可行的候选函数的参数匹配所需要进行的转换。通常，从最佳到最差的顺序如下：
- 完全匹配，但常规函数优于模版
- 提升转化（例如，*char* 和 *short* 自动转换为 *int*，*float* 自动转换为 *double*）
- 标准转化（例如，*int* 转换为 *char*，*long* 转换为 *double*）
- 用户定义转换，如类声明中的转换




