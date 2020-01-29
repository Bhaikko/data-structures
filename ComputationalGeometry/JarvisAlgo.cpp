#include <iostream>
#include <vector>

struct Point
{
    int x;
    int y;
};

int orientation(Point p1, Point p2, Point p3)
{
    int value = ((p2.y - p1.y) * (p3.x - p2.x)) - ((p2.x - p1.x) * (p3.y - p2.y));
    if (value == 0) {
        return 0;
    }
    return (value > 0) ? 1 : 2;
}

void convexHull(Point points[], int size)
{
    if (size < 3) {
        std::cout << "Convex Hull Not Possible" << std::endl;
        return;
    }

    std::vector<Point> hull;

    int l = 0;
    for (int i = 1; i < size; i++) {
        if (points[i].x < points[l].x) {
            l = i;
        }
    }

    int p = l, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % size;

        for (int i = 0; i < size; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;

    } while (p != l);

    for (int i = 0; i < hull.size(); i++) {
        std::cout << "(" << hull[i].x << ", " << hull[i].y << ")" << std::endl;
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