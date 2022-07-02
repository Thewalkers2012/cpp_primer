// namessp.cc -- using namespaces
#include <iostream>
#include "namesp.h"

void other(void);

void another(void);

int main() {
    using debts::Debt;
    using debts::showDebt;

    Debt golf = {
        {
            "Benny",
            "Goatsniff"
        },
        120.0
    };

    showDebt(golf);
    other();
    another();

    return 0;
}

void other(void) {
    using std::cout;
    using std::endl;

    using namespace debts;

    Person dg = {
        "Doodles",
        "Glister"
    };

    showPerson(dg);
    cout << endl;

    Debt zippy[3];
    int i;

    for (i = 0; i < 3; i++)
        getDebt(zippy[i]);

    for (i = 0; i < 3; i++)
        showDebt(zippy[i]);

    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
}

void another(void) {
    using pers::Person;

    Person collector = {
        "Milo",
        "Rightshift"
    };

    pers::showPerson(collector);

    std::cout << std::endl;
}

/*
output:
    Goatsniff, Benny: $120
    Glister, Doodles
    Enter first name: Cleve
    Enter last name: Delaroux
    Enter debt: 120
    Enter first name: Eddie
    Enter last name: Fiotox
    Enter debt: 200
    Enter first name: Arabella
    Enter last name: Binx
    Enter debt: 100
    Delaroux, Cleve: $120
    Fiotox, Eddie: $200
    Binx, Arabella: $100
    Total debt: $420
    Rightshift, Milo
*/