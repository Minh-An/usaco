#include <string>
using namespace std;

class Point {
public:

    Point(int x, int y): x(x), y(y) {}
    double slopeTo(Point that)
    {
        return (that.y - y) / (that.x - x);
    }

    bool CompareBySlope(const Point &p1, const Point &p2)
    {
        return slopeTo(p1) < slopeTo(p2);
    }

private:
    int x;
    int y;

    friend bool operator== (const Point &p1, const Point &p2);
    friend bool operator< (const Point &p1, const Point &p2);
    friend bool operator> (const Point &p1, const Point &p2);
    friend class LineSegment;
};

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
 