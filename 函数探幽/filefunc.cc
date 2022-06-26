// filefunc.cc -- function with ostream & parameter
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void file_it(ostream &os, double fo, const double fe[], int n);

const int LIMIT = 5;

int main(void) {
    ofstream fout;
    const char* fn = "ep-data.txt";

    fout.open(fn);
    if (!fout.is_open()) {
        cout << "Can't open " << fn << ".Bye\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your "
        << "telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT << " exepieces:\n";
    for (int i = 0; i < LIMIT; i++) {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);

    cout << "Done\n";

    return 0;
}

void file_it(ostream &os, double fo, const double fe[], int n) {
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); // save initial formatting state

    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++) {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }
    os.setf(initial); // response initial formatting state
}

/*
output:
Enter the focal length of your telescope objective in mm: 1800
Enter the focal lengths, in mm, of 5 exepieces:
Eyepiece #1: 30
Eyepiece #2: 19
Eyepiece #3: 14
Eyepiece #4: 8.8
Eyepiece #5: 7.5
Focal length of objective: 1800 mm
  f eyepiece  magnification
        30.0             60
        19.0             95
        14.0            129
         8.8            205
         7.5            240
Done
*/