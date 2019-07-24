#include "point.h"
#include <cmath>

class LineSegment{
private:
    Point p;
    Point q;
    friend class Point;
public:
    LineSegment(Point p, Point q): p{p}, q{q} {}

    double Distance() const
    {
        return hypot(p.x - q.x, p.y - q.y);
    }

    static bool CompareByDist(const LineSegment &l1, const LineSegment &l2)
    {
        return l1.Distance() < l2.Distance();
    }
};