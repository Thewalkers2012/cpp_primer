// usebrass1.cc -- testing bank account classes
#include <iostream>
#include "brass.h"

int main() {
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Depositing $1000 into the Hogg Account: \n";
    Hoggy.Deposit(1000.0);
    cout << "New balance: $" << Hoggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Pigg Account: \n";
    Piggy.Withdraw(4200.00);

    cout << "Pigg account balance: $" << Piggy.Balance() << endl;
    cout << "Withdraw $4200 from Hogg Account: \n"; 
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();

    return 0;
}

/*
output:
Client: Porcelot Pigg
Account Number: 381299
Balance: $4000.00

Client: Horatio Hogg
Account Number: 382288
Balance: $3000.00
Maximum loan: $500.00
Owed to bank: $0.00
Loan Rate: 10.00%

Depositing $1000 into the Hogg Account: 
New balance: $4000.00
Withdrawing $4200 from the Pigg Account: 
Withdrawal account of $4200.00 exceeds your balance.
Withdrawal canceled.
Pigg account balance: $4000.00
Withdraw $4200 from Hogg Account: 
Bank advance: $200.00
Finance charge: $20.00
Client: Horatio Hogg
Account Number: 382288
Balance: $0.00
Maximum loan: $500.00
Owed to bank: $220.00
Loan Rate: 10.00%
*/