#include <vector>
#include <set>

#include "line_segment.h"


class BruteCollinearPoints {
private:
    set<LineSegment> segments;

public:

    BruteCollinearPoints(vector<Point>& points)
    {
        sort(points.begin(), points.end());
        for(int i = 0; i < points.size()-3; i++)
        {
            for(int j = i+1; j < points.size()-2; j++)
            {
                for(int k = j+1; k < points.size()-1; k++)
                {
                    for(int l = k+1; l < points.size(); l++)
                    {
                        if(points[i].slopeTo(points[j]) == points[k].slopeTo(points[j]) &&
                            points[i].slopeTo(points[j]) == points[k].slopeTo(points[l]) &&
                            points[i].slopeTo(points[j]) == points[l].slopeTo(points[i]))
                        {
                            segments.emplace(LineSegment(points[i],points[l]));
                        }
                    }
                }
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