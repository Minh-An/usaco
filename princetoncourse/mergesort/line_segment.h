#include "point.h"
#include <cmath>

class LineSegment{
private:
    Point p;
    Point q;
    friend class Point;
    friend ostream & operator << (ostream &out, const LineSegment &ls);
    friend bool operator== (const LineSegment &l1, const LineSegment &l2);
    friend bool operator< (const LineSegment &l1, const LineSegment &l2);
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

ostream & operator << (ostream &out, const LineSegment &ls)
{
    out << ls.p << " -> " << ls.q;
    return out;
}

bool operator< (const LineSegment &l1, const LineSegment &l2)
{
    //if (l1.p == l2.p) return  l1.q < l2.q;
    //return l1.p < l2.p;
    return l1.p.slopeTo(l1.q) < l2.p.slopeTo(l2.q);
}

bool operator== (const LineSegment &l1, const LineSegment &l2)
{
    return l1.p == l2.p && l1.q == l2.q;
}