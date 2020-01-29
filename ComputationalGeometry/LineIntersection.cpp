#include <iostream>
#include <algorithm>

struct Point
{
    int x;
    int y;
};

Point getVector(Point p1, Point p2)
{
    Point vector;
    vector.x = p1.x - p2.x;
    vector.y = p1.y - p2.y;

    return vector;
}

int direction(Point p1, Point p2, Point p3) 
{
    Point vector1 = getVector(p3, p1);
    Point vector2 = getVector(p2, p1);    

    int value = (vector1.x * vector2.y) - (vector2.x * vector1.y);

    return value;
}

bool onSegment(Point p1, Point p2, Point p3)
{
    if (p2.x <= std::max(p1.x, p3.x) && p2.x >= std::min(p1.x, p3.x) && p2.y <= std::max(p1.y, p3.y) && p2.y >= std::min(p1.y, p3.y))  {
        return true; 
    } else {
        return false;
    }
}

bool segmentIntersect(Point p1, Point p2, Point p3, Point p4)
{
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    } else if (d1 == 0 && onSegment(p3, p4, p1)) {
        return true;
    } else if (d2 == 0 && onSegment(p3, p4, p2)) {
        return true;
    } else if (d3 == 0 && onSegment(p1, p2, p3)) {
        return true;
    } else if (d4 == 0 && onSegment(p1, p2, p4)) {
        return true;
    } else {
        return false;
    }

}

int main()
{
    Point points[4];

    // points[0].x = 2;
    // points[0].y = 4;

    // points[1].x = 2;
    // points[1].y = 6;
    
    // points[2].x = 1;
    // points[2].y = 4;
    
    // points[3].x = 1;
    // points[3].y = 6;

    points[0].x = 2;
    points[0].y = 3;

    points[1].x = 3;
    points[1].y = 2;
    
    points[2].x = 2;
    points[2].y = 2;
    
    points[3].x = 3;
    points[3].y = 3;

    if (segmentIntersect(points[0], points[1], points[2], points[3])) {
        std::cout << "Intersects" << std::endl;
    } else {
        std::cout << "Does not intersect" << std::endl;
    }

    return 0;
}