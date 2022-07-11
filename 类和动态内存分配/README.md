## 12.1 动态内存和类

#### 12.1.1 复习范式和静态类成员

*stringBad.cc* 程序解析 
```cpp
int StringBad::num_strings = 0;
```
这条语句将静态成员 *num_strings* 初始化为 0。请注意，不能在类声明中初始化静态成员，这是因为声明描述了如何分配内存，但并不分配内存。
初始化是在方法文件中的，而不是在类声明文件中进行的，这是因为类声明位于头文件中

字符串并不是保存在对象里面的，字符串单独保存在堆内存中，对象仅保存了指出到哪里去找字符串信息。

#### 12.1.2 隐式成员函数
- 默认构造函数，如果没有定义构造函数
- 复制构造函数，如果没有复制
- 赋值操作符，如果没有定义
- 默认析构函数，如果没有定义
- 地址操作符，如果没有定义

1. 默认构造函数
如果没有提供任何构造函数，*C++* 将创建默认构造函数。
带参数的构造函数也可以是构造函数，如：
```cpp
Klunk::Klunk(int n = 0) // explicit default constructor
{

}
```

2. 复制构造函数
将一个对象复制到一个新创建的对象中。也就是说，它用于初始化过程中，而不是常规的赋值过程中。类的复制构造函数通常如下：
```cpp
Class_name(const Class_name&);
```
(1) 何时调用拷贝构造函数
调用场景：
```cpp
StringBad ditto(motto); // calls StringBad(const StringBad &);
StringBad metoo = metto; // calls StringBad(const StringBad &);
StringBad also = StringBad(motto); 
```

(2) 拷贝构造函数的功能
默认的拷贝构造函数逐个复制非静态成员（成员复制也称为浅复制），复制的是成员的值。下述语句：
```cpp
StringBad sailor = sports;
```
与下面代码等价
```cpp
StringBad sailor;
sailor.str = sports.str;
sailor.len = sports.len;
```

(3) 拷贝构造函数哪里出了问题

4. 使用显式复制构造函数来解决问题
解决方式为深拷贝。
```cpp
StringBad::StringBad(const String &st) {
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << num_strings << ": \"" << str
        << "\" object created\n";
}
```

5. 赋值操作符
*C++* 允许对象赋值，这是通过自动为类重载赋值操作符实现的，这种操作原型为：
```cpp
Class_name& Class_name::operator=(const Class_name&);
```
它接受并返回一个指向类对象的引用。

(1) 何时使用赋值操作符
将已有的对象赋给另一个对象时，将使用重载的操作符：  
```cpp
StringBad headline1("Celery Stalks at Midnight");
...
StringBad knot;
knot = headline1;
```

6. 赋值的问题出在哪里

7. 解决赋值的问题
- 由于目标对象可能引用了以前分配的数据，所以函数应使用 *delete[]* 来释放这些数据
- 函数应避免将对象赋给自身；否则，给对象赋值前，释放内存操作可能删除对象的内容
- 函数返回一个指向调用对象的引用

```cpp
StringBad& StringBad::operator=(const StringBad &) {
    if (this == &st) {
        return *this;
    }
    delete []str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}
```

#### 12.1.3 改进后的新 *String* 类
1. 修改后的默认构造函数
```cpp
String::String() {
    len = 0;
    str = new char[1];
    str[0] = '\0';
}
```

为什么使用 `str = new char[1]` 而不使用 `str = new char`
上面两种方式分配内存量相同，区别在于前者与类析构函数兼容，而后者不兼容。
析构函数包含代码：
```cpp
delete []str;
```

2. 比较成员函数
```cpp
bool operator<(const String &st1, const String &st2) {
    if (std::strcmp(st1.str, st2.str) > 0) {
        return true;
    } else {
        return false;
    }
}
```
简化：
```cpp
bool operator<(const String &st1, const String &st2) {
    return (std::strcmp(st1.str, st2.str) < 0);
}
```

另外两个比较函数：
```cpp
bool operator>(const String &st1, const String &st2) {
    return st1 < st2;
}

bool operator==(const String &st1, const String &st2) {
    return (std::strcmp(st1.str, st2.str));
}
```

3. 使用中括号表示法来访问字符
```cpp
char &String::operator[](int i) {
    return str[i];
}
```

4. 静态成员函数
首先不能够通过对象调用静态成员函数；实际上，静态成员函数甚至不能使用 *this* 指针。如果静态成员函数是在共有部分声明的，则可以使用类名和作用域解析操作符来调用它。

```cpp
static int HowMany();
// 调用方式
int count = String::HowMany();
```

5. 进一步重载赋值操作符

#### 12.1.4 在构造函数中使用 *new* 时应注意什么
- 如果在构造函数中使用 *new* 来初始化指针成员，则应在析构函数中使用 *delete*
- *new* 和 *delete* 必须相互兼容。*new* 对应 *delete*，*new[]* 对应 *delete[]*
- 如果有多个构造函数，则必须以相同的方式使用 *new*，要么都带中括号，要么都不带。
- 应定义一个拷贝构造函数，通过深度复制将一个对象初始化为另一个对象。通常，这种构造函数与下面类似。
```cpp
String::String(const String &st) {
    num_strings++;
    len = st_len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}
```
- 具体的说，拷贝构造函数应分配足够多的空间来存储复制的数据，并复制数据，而不仅仅是数据的地址。
- 应当定一个一个赋值操作符，通过深度拷贝将一个对象复制给另外一个对象。

#### 12.1.5 有关返回对象的说明
1. 返回指向 *const* 的引用
2. 返回指向非 *const* 对象的引用
3. 返回对象

#### 12.1.7 复习各种技术
1. 重载操作符
2. 转换函数
3. 其构造函数使用 *new* 的类


