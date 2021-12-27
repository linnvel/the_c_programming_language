#include <stdio.h>

// declare a structure
struct point {
    int x;
    int y;
};

// structure can be nested
struct rect {
    struct point pt1;
    struct point pt2;
};

int main(){

    // initialize structure by following its definition with a list of initializers.
    struct point pt = { 320, 200 };
    printf("%d, %d\n", pt.x, pt.y);
    
    // compute the distance from the origin (0,0) to pt
    double dist, sqrt(double);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("distance from (0,0) to (%d,%d) is %f", pt.x, pt.y, dist);
}