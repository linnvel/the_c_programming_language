#include <stdio.h>
#include "structure.h"

#define XMAX 100
#define YMAX 100

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct {
    int len;
    char *str;
} *p;

int main(){

    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);
    void printpoint(struct point);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);
    printpoint(middle);

    struct point add;
    struct point addpoints(struct point, struct point);
    int ptinrect(struct point, struct rect);

    add = addpoints(screen.pt1, screen.pt2);
    printpoint(add);
    printpoint(screen.pt1);
    printf("middle point in rect: %d\n", ptinrect(middle, screen));
    printf("add point in rect: %d\n", ptinrect(add, screen));

    // structure pointer
    struct point origin = {100, 200}, *pp;
    pp = &origin;
    // parentheses are necessary here because *pp.x means *(pp.x), 
    // which is illegal because x is not a pointer.
    printf("origin is (%d, %d)\n", (*pp).x, (*pp).y); 

    struct rect r, *rp = &r;
    r.pt1 = makepoint(0, 0);
    r.pt2 = makepoint(XMAX, YMAX);
    // parentheses are not necessary here because both . and -> associate from left to right.
    printf("r.pt1.x = %d\n", r.pt1.x);
    printf("rp->pt1.x = %d\n", rp->pt1.x);
    printf("(r.pt1).x = %d\n", r.pt1.x);
    printf("(rp->pt1).x = %d\n", rp->pt1.x);

    // todo: segmentation fault
    p->len = 5;
    p->str = "hello";
    printf("++p->len = %d\n", ++p->len); // increment len, not p, equivalent to ++(p->len)
    printf("*p->str = %s\n", p->str);

};

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
};

/* addpoints: add two points */
struct point addpoints(struct point p1, struct point p2) // structure parameters are passed by value
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;    
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}

void printpoint(struct point pt)
{
    printf("%d, %d\n", pt.x, pt.y);
}

