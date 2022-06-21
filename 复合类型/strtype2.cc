// strtype2.cc -- aasigning, adding, and appending
#include <iostream>
#include <string>

int main() {
    using namespace std;

    string s1 = "penguin";
    string s2, s3;

    cout << "You can assign one string object to another: s2 = s1\n";
    s2 = s1;
    cout << "s1 = " << s1 << " , " << "s2 = " << s2 << endl;
    cout << "You can assign a C-style string to a string object.\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";
    cout << "s2: " << s2 << endl;

    cout << "You can concatenate strings: s3 = s1 + s2\n";
    s3 = s1 + s2;
    cout << "s3: " << s3 << endl;
    cout << "You can append strings.\n";
    s1 += s2;
    cout << "s1 += s2 yield s1 = " << s1 << endl;
    s2 += " for a day";
    cout << "s2 += \"for a day\" yield s2 = " << s2 << endl;

    return 0;
}

/*
output:
    You can assign one string object to another: s2 = s1
    s1 = penguin , s2 = penguin
    You can assign a C-style string to a string object.
    s2 = "buzzard"
    s2: buzzard
    You can concatenate strings: s3 = s1 + s2
    s3: penguinbuzzard
    You can append strings.
    s1 += s2 yield s1 = penguinbuzzard
    s2 += "for a day" yield s2 = buzzard for a day
*/