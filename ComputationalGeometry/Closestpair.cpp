#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

struct Point
{
    int x;
    int y;
};

bool compareX(Point p1, Point p2) {
    return (p1.x - p2.x);
}

bool compareY(Point p1, Point p2) {
    return (p1.y - p2.y);
}

float distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(Point p[], int size)
{
    float min = INT_MAX * 1.0; 
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            const float dis = distance(p[i], p[j]);
            if (dis < min) {
                min = dis;
            }
        }
    }

    return min;
}

float stripCloset(Point strip[], int size, float d)
{
    float min = d;
    std::sort(strip, strip + size, compareY);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++) {
            const float dis = distance(strip[i], strip[j]);
            if (dis < min) {
                min = dis;
            }
        }
    }

    return min;
}

float closetUtility(Point p[], int size) 
{
    if (size <= 3) {
        return bruteForce(p, size);
    }

    int mid = size / 2;
    Point midPoint = p[mid];

    float dl = closetUtility(p, mid);
    float dr = closetUtility(p + mid, size - mid);

    float d = std::min(dl, dr);

    Point strip[size];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (abs(p[i].x - midPoint.x) < d) {
            strip[j] = p[i];
            j++;
        }
    }

    return std::min(d, stripCloset(strip, j, d));
}

float closet(Point p[], int size)
{
    std::sort(p, p + size, compareX);
    return closetUtility(p, size);
}

int main() 
{ 
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
	int n = sizeof(P) / sizeof(P[0]); 
	std::cout << "The smallest distance is " << closet(P, n) << std::endl;
	return 0; 
} 