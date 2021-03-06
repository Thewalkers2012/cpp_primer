// string1.h -- fixed and argumented string class definition
#include <iostream>
using std::ostream;
using std::istream;

#ifndef STRING1_H_
#define STRING1_H_

class String {
private:
    char *str; // pointer to string
    int len;
    static int num_strings; // number of object
    static const int CINLIM = 80; // cin input limit

public:
    // constructors and other methods
    String(const char* s); // constructor

    String(); // default constructor

    String(const String &); // copy constructor

    ~String(); // destructor

    int length() const {
        return len;
    }

    // overloaded operator methods
    String &operator=(const String &);

    String &operator=(const char *);

    char &operator[](int i);

    const char &operator[](int i) const;

    // overloaded operator friends
    friend bool operator<(const String &st, const String &st2);

    friend bool operator>(const String &st, const String &st2);

    friend bool operator==(const String &st, const String &st2);

    friend ostream &operator<<(ostream &os, const String &st);

    friend istream &operator>>(istream &is, String &st);

    // static function
    static int HowMany();
};

#endif