// brass.cc -- bank account class methods
#include <iostream>
#include <cstring>
#include "brass.h"

using std::cout;
using std::ios_base;
using std::endl;
// Brass methods

Brass::Brass(const char *s, long an, double bal) {
    std::strncpy(fullName, s, MAX - 1);
    fullName[MAX - 1] = '\0';
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt) {
    if (amt < 0) {
        cout << "Negative deposit not allowed: "
            << "deposit is cancelled.\n";
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt) {
    if (amt < 0) {
        cout << "Negative deposit not allowed: "
            << "deposit is cancelled.\n";
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        cout << "Withdrawal account of $" << amt
            << " exceeds your balance.\n"
            << "Withdrawal canceled.\n";
    }
} 

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    // set up ###.## format
    ios_base::fmtflags inititalState = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    cout.setf(inititalState);
}

// BrassPlus Methods
BrassPlus::BrassPlus(const char *s, long an, double bal, 
    double ml, double r) : Brass(s, an, bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// redefine how ViewAcct() works
void BrassPlus::ViewAcct() const {
    // set up ###.## format
    ios_base::fmtflags inititalState = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    Brass::ViewAcct();
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";
    cout.setf(inititalState);
}

// redefine how withdraw() works
void BrassPlus::Withdraw(double amt) {
    // set up ###.## format
    ios_base::fmtflags inititalState = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    double bal = Balance();
    if (amt <= bal) {
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl; 
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }

    cout.setf(inititalState);
}