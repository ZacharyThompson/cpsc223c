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
	//if x and y coords are inside the
	//bounds of the rectangle return true
	if (p.x >= r.pt1.x &&
	    p.x <= r.pt2.x &&
	    p.y >= r.pt1.y &&
	    p.y <= r.pt2.y)
		return 1;

	return 0;
}

int rectPerimeter(rect r) {
	int difx = r.pt2.x - r.pt1.x; //width
	int dify = r.pt2.y - r.pt1.y; //height

	//Get rid of negative numbers
	if (difx < 0)
		difx = -difx;
	if (dify < 0)
		dify = -dify;

	return 2*(difx + dify); //P = 2W + 2H
}

int rectArea(rect r) {
	int difx = r.pt2.x - r.pt1.x; //width
	int dify = r.pt2.y - r.pt1.y; //height

	//Get rid of negative numbers
	if (difx < 0)
		difx = -difx;
	if (dify < 0)
		dify = -dify;

	return difx*dify; //A = W x H
}

struct point makePoint(int x, int y) {
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

int main() {
	int inside, perimeter, area;

	rect r1;
	r1.pt1 = makePoint(10, 20);
	r1.pt2 = makePoint(30, 40);
	inside = ptinrect(r1, makePoint(12, 25));
	perimeter = rectPerimeter(r1);
	area = rectArea(r1);

	printf("R1 Inside: %d\n", inside);
	printf("R1 Perimeter: %d\n", perimeter);
	printf("R1 Area: %d\n", area);


	rect r2;
	r2.pt1 = makePoint(-16, -34);
	r2.pt2 = makePoint(12, -5);
	inside = ptinrect(r2, makePoint(15, 7));
	perimeter = rectPerimeter(r2);
	area = rectArea(r2);

	printf("R2 Inside: %d\n", inside);
	printf("R2 Perimeter: %d\n", perimeter);
	printf("R2 Area: %d\n", area);
	return 0;
}
