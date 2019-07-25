#include <vector>
#include <set>

#include "line_segment.h"

class FastCollinearPoints {
private:
    set<LineSegment> segments;

public:

    FastCollinearPoints(vector<Point>& points)
    {
        vector<Point> pointsCopy(points.size());
        copy(points.begin(), points.end(), pointsCopy.begin());
        sort(points.begin(), points.end());
        for(int i = 0; i < points.size(); i++)
        {
            Point p = points[i];
            sort(pointsCopy.begin(), pointsCopy.end());
            stable_sort(pointsCopy.begin(), pointsCopy.end(), [p](const Point& p1, const Point& p2) {
                return p.slopeTo(p1) < p.slopeTo(p2);
            } );
            double slope = p.slopeTo(pointsCopy[i+1]);
            int count = 2;
            for(int j = i+1; j < pointsCopy.size(); j++)
            {
                if (p.slopeTo(pointsCopy[j]) == slope)
                {
                    count++;
                }
                else {
                    if(count >= 4)
                    {
                        segments.emplace(LineSegment(p, pointsCopy[j-1]));
                    }
                    slope = p.slopeTo(pointsCopy[j]);
                    count = 2;
                }
            }
            if(count >= 4)
            {
                segments.emplace(LineSegment(p, pointsCopy[points.size()-1]));
            }
        }
    }

    int NumberOfSegments()
    {
        return segments.size();
    }

    set<LineSegment> GetSegments()
    {
        return segments;
    }
};