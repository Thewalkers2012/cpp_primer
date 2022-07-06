// stonewt.cc -- Stonewt methods 
#include "stonewt.h"
#include <iostream>

using std::cout;

// construct Stonewt object from double value
StoneWt::StoneWt(double lbs) {
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn;
    pounds = lbs;
}

// construct Stonewt object from stones, double value
StoneWt::StoneWt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

StoneWt::StoneWt() {
    stone = pounds = pds_left = 0;
}

StoneWt::~StoneWt() {

}

// show weight in stones
void StoneWt::show_stn() const {
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void StoneWt::show_lbs() const {
    cout << pounds << " pounds\n";
}

// conversion function
StoneWt::operator int() const {
    return int(pounds + 0.5);
}

StoneWt::operator double() const {
    return pounds;
}