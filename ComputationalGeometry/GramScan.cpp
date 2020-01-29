#include <iostream>
#include <stack>
#include <algorithm>

struct Point
{
    int x;
    int y;
};

Point p0;

Point nextToTop(std::stack<Point> &s)
{
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;
}

int distanceSq(Point p1, Point p2)
{
    return ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
}

int orientation(Point p1, Point p2, Point p3)
{
    int value = ((p2.y - p1.y) * (p3.x - p2.x)) - ((p2.x - p1.x) * (p3.y - p2.y));
    if (value == 0) {
        return 0;
    } 

    return (value > 0) ? 1 : 2;
}

bool compare(Point p1, Point p2)
{
    int o = orientation(p0, p1, p2);
    if (o == 0) {
        return (distanceSq(p0, p2) >= distanceSq(p0, p1)) ? -1 : 1;
    }

    return (o == 2) ? -1 : 1;
}

void convexHull(Point points[], int size)
{
    int yMin = points[0].y;
    int min = 0;
    for (int i = 1; i < size; i++) {
        int y = points[i].y;

        if ((y < yMin) || (yMin == y && points[i].x < points[min].x)) {
            yMin = points[i].y;
            min = i;
        }
    }

    std::swap(points[0], points[min]);

    p0 = points[0];
    
    std::sort(points + 1, points + size, compare);

    int m = 1;
    for (int i = 1; i < size; i++) {
        while (i < size - 1 && orientation(p0, points[i], points[i + 1]) == 0) {
            i++;
        }

        points[m] = points[i];
        m++;
    }

    if (m < 3) {
        return;
    }

    std::stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    for (int i = 3; i < m; i++) {
        while (orientation(nextToTop(s), s.top(), points[i]) != 2) {
            s.pop();
        }

        s.push(points[i]);
    }

    while (!s.empty()) {
        Point p = s.top();
        std::cout << "(" << p.x << ", " << p.y <<")" << std::endl; 
        s.pop(); 
    }
}


int main()
{

    Point points[] = {
        {0 ,3},
        {2 ,2},
        {1 ,1},
        {2 ,1},
        {3 ,0},
        {0 ,0},
        {3, 3}
    };

    int size = sizeof(points) / sizeof(points[0]);
    convexHull(points, size);
    return 0;
}
