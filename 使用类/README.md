## 11.1 操作符重载

操作符函数的格式
```cpp
operator op (argument-list);
```

## 11.2 计算时间：一个操作符重载范例

#### 11.2.1 添加加法操作符

#### 11.2.2 重载限制
1. 重载后的操作符必须至少有一个操作符是用户定义的类型，这将防止用户为标准类型重载操作符。因此，不能将减法操作符（-）重载为计算两个 *double* 值的和，而不是他们的差。
2. 使用操作符时不能违反原来的句法规则。
```cpp
int x;
Time shiva;
% x;
% shiva;
```
3. 不能重新定义新的操作符
4. 不能重载下面的操作符

#### 11.2.3 其他重载操作符

## 11.3 友元简介
*C++* 控制对类对象私有部分的访问。公有类方法提供唯一的访问途径。

友元有三种
- 友元函数
- 友元类
- 友元成员函数

在 *Time* 类范例中，重载的乘法操作符与其他两种重载操作符的差别在于，它使用两种不同的类型。也就是说，加法和减法都结合两个 *Time* 值，而乘法操作符将一个 *Time* 值和一个 *double* 值结合在一起。
```cpp
A = B * 2.75;
将被转换为下面的成员函数调用
A = B.operator*(2.75);
==>
A = 2.75 * B; // cannot correspond to a member function
```
从概念上说，`2.75 * B` 和 `B * 2.75` 相同，但第一个表达式不对应成员函数。

#### 11.3.1 创建友元
1. 创建友元函数的第一步是将其原型放到类声明中，并在原型前面加上 *friend*
```cpp
friend Time operator*(double m, const Time &t);
```

- 虽然 *operator\*()* 函数是在类声明中声明的，但它不是成员函数，因此不能使用成员操作符调用。
- 虽然 *operator\*()* 函数不是成员函数，但是它与成员函数访问权限相同。 

2. 编写函数的定义。因为它不是成员函数，所以不要使用 *Time::* 限定符。另外，不要在定义中使用关键字 *friend*
```cpp
Time operator*(double m, const Time &t) {
    Time result;
    long totalminutes = t.hours * mult * 60 + t.minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
```

#### 11.3.2 常用的友元：重载 *<<* 操作符
1. *<<* 的第一个重载版本
要使 *Time* 类知道使用 *cout*，必须使用友元函数。

使用两个对象，其中第一个是 *ostream* 类对象 （cout）。如果使用一个 *Time* 成员函数来重载 *<<*，*Time* 对象将是第一个操作数。

2. *<<* 的第二种重载版本

## 11.4 重载操作符：作为成员函数还是非成员函数

*Time* 类的加法操作符在 *Time* 类中的声明原型如下：
```cpp
Time operator+(const Time &t);
```
这个类也可以使用下面的原型：
```cpp
friend Time operator+(const Time &t1, const Time &t2);
```
加法操作需要两个操作数。对于成员函数版本来说，一个操作数通过 *this* 指针隐式传递，另一个通过函数参数显式传递。对于友元函数来说，两个操作数都作为参数传递。

这两种原型都与表达式 *T2 + T3* 匹配，其中 *T2 和 T3* 都是 *Time* 类型的对象。编译器将转化为下面的语句   
```cpp
T1 = T2 + T3
```
转换为下面两个的任意一个
```cpp
T1 = T2.operator+(T3);
T1 = operator+(T2, T3);
```

在定义操作符时，必须选择其中的一种格式，而不能同时选择两种格式。

## 11.5 再谈重载：矢量类

## 11.6 类的自动转换和强制类型转换
```cpp
long count = 8; // int value 8 converted to type long
double time = 11; // int value 11 converted to double
int side = 3.33 // double value convert to type int 3
```

```cpp
StoneWt mycat;
mycat = 19.6;
```

最新的 *C++* 实现新增了一个关键字 *explicit* ，使用这个关键字来关闭自动转换特性。

```cpp
explicit StoneWt(double lbs); // no implicit conversion allowed
```
这将关闭上面的隐式转换，但仍然允许显示转换。    
```cpp
StoneWt myCat;
myCat = 19.6;
mycat = StoneWt(19.6);
mycat = (StoneWt)19.6;
```

#### 11.6.2 转换函数
程序中将数字转换为 *Stonewt* 对象，可以相反做吗。
可以这样做，但不是使用构造函数，构造函数用于某种类型到另外一种类型的转换，要进行相反的转换，就要使用转换函数。

转换函数形式
```cpp
operator typeName();
```

- 转换函数必须是类方法
- 转换函数不能指定返回类型
- 转换函数不能有参数




