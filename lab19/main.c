/*
Write function ptinrect tests whether a point structure is inside a rectangle structure. 

Write function rectPerimeter that that returns the perimeter of a rectangle structure 

Write function rectArea that that returns the area of a rectangle structure
*/

#include <stdio.h>

typedef struct point {
	int x;
	int y;
}point;

typedef struct rect {
	point pt1; //bottom left
	point pt2; //top right
}rect;

int ptinrect(rect r, point p) {
	if (p.x >= r.pt1.x && 
	    p.x <= r.pt2.x && 
	    p.y >= r.pt1.y && 
	    p.y <= r.pt2.y)
		return 1;

	return 0;
}

int rectPerimeter(rect r) {
	int difx = r.pt2.x - r.pt1.x;
	int dify = r.pt2.y - r.pt1.y;
	return 2*(difx + dify)
}

int rectArea(rect r) {
	int difx = r.pt2.x - r.pt1.x;
	int dify = r.pt2.y - r.pt1.y;
	return difx*dify;
}

struct point makePoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main() {
	rect r1;
	r1.pt1 = makePoint(10, 20);
	r1.pt2 = makePoint(30, 40);


	return 0;
}
