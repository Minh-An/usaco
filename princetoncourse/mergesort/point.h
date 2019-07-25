#include <string>
#include <iostream>
#include <limits>
using namespace std;

class Point {
private:
    int x;
    int y;

    friend bool operator== (const Point &p1, const Point &p2);
    friend bool operator< (const Point &p1, const Point &p2);
    friend bool operator> (const Point &p1, const Point &p2);

    friend ostream & operator << (ostream &out, const Point &p);

    friend class LineSegment;
public:

    Point(): x(0), y(0) {}

    Point(int x, int y): x(x), y(y) {}

    double slopeTo(Point that) const
    {
        if (that.x == x) 
        {
            if (that.y == y) return -1 * numeric_limits<double>::infinity();
            else    return numeric_limits<double>::infinity();
        }
        return double(that.y - y) / double(that.x - x);
    }
};


ostream & operator << (ostream &out, const Point &p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

bool operator== (const Point &p1, const Point &p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}
bool operator!= (const Point &p1, const Point &p2)
{
    return !(p1 == p2);
}
bool operator> (const Point &p1, const Point &p2)
{
    return p1.y == p2.y ? p1.x > p2.x : p1.y > p2.y;
}
bool operator>= (const Point &p1, const Point &p2)
{
    return p1 == p2 || p1 > p2;
}
bool operator< (const Point &p1, const Point &p2)
{
    return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
}
bool operator<= (const Point &p1, const Point &p2)
{
    return p1 == p2 || p1 < p2;
}
 