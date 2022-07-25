/*
饿汉：
  单例类进行定义的时候就进行初始化
  线程安全
*/

class singleton
{
private:
  singleton();
  static singleton* p;

public:
  static singleton* instance();
};

singleton* singleton::p = new singleton();

singleton* singleton::instance()
{
  return p;
}