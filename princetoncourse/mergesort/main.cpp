#include <fstream>
#include <iostream>
//#include "bruteforce_collinear.h"
#include "fast_collinear.h"

int main(int argc, char const *argv[])
{
    ifstream ifs(argv[1], ifstream::in);
    int n;
    ifs >> n;
    
    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        int x, y; 
        ifs >> x;
        ifs >> y;
        Point p(x,y);
        points[i] = p;
    }

    FastCollinearPoints collinear = FastCollinearPoints(points);
    //BruteCollinearPoints collinear = BruteCollinearPoints(points);
    set<LineSegment> segments = collinear.GetSegments();
    for (LineSegment segment: segments) {
        cout << segment << endl;
    }
}