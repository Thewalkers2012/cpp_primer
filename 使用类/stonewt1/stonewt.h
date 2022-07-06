// stonewt.h -- definition for Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

class StoneWt {
private:
    enum {
        Lbs_per_stn = 14
    };
    int stone;
    double pds_left;
    double pounds;

public:
    StoneWt(double lbs);

    StoneWt(int stn, double lbs);

    StoneWt();

    ~StoneWt();

    void show_lbs() const;

    void show_stn() const;

    // conversion function
    operator int() const;

    operator double() const;
};


#endif