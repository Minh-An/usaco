#include <vector>

#include "line_segment.h"


class BruteCollinearPoints {

private:
    vector<LineSegment> segments;

public:

    BruteCollinearPoints(vector<Point> points)
    {
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i; j < points.size(); j++)
            {
                for(int k = j; k < points.size(); k++)
                {
                    for(int l = k; l < points.size(); l++)
                    {
                        if(points[i].slopeTo(points[j]) == points[k].slopeTo(points[j]) &&
                            points[i].slopeTo(points[j]) == points[k].slopeTo(points[l]) &&
                            points[i].slopeTo(points[j]) == points[l].slopeTo(points[i]))
                        {
                            vector<LineSegment> lines{
                                LineSegment(points[i], points[j]),
                                LineSegment(points[j], points[k]),
                                LineSegment(points[k], points[l]),
                                LineSegment(points[l], points[i])};
                            vector<LineSegment>::iterator result = max_element(lines.begin(), lines.end(), LineSegment::CompareByDist);
                            segments.push_back(*result);
                        }
                    }
                }
            }
        }
    }
    int numberOfSegments()
    {
        return segments.size();
    }
    vector<LineSegment> segments()
    {
        return segments;
    }
};