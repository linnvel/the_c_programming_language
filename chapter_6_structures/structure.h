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
