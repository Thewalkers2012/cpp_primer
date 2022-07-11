// stringbad.h -- flawed string class definiton
#include <iostream>
#ifndef STRINGBAD_H
#define STRINGBAD_H

class StringBad {
private:
    char *str;
    int len;
    static int num_strings;

public:
    StringBad(const char *s);

    StringBad();

    ~StringBad();

    // friend function
    friend std::ostream& operator<<(std::ostream &os, const StringBad &st);
};

#endif