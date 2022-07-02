// coordin.h -- structure templates and functions prototypes
// structure templates
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar {
    double distance; // distance from origin
    double angle; // direction from origin
};

struct rect {
    double x;
    double y;
};

// prototypes
polar rect_to_polar(rect xypos);

void show_polar(polar dapos);

#endif