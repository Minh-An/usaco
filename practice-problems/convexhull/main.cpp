#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
#include <math.h> 

using namespace std;

bool Clockwise(const pair<int,int>& a, const pair<int,int>& b, const pair<int,int>& c)
{
    int area2 = (b.first-a.first) * (c.second - a.second) - (b.second - a.second)*(c.first-a.first);
    return area2 <= 0;
}

vector< pair<int,int > > ConvexHull(vector< pair<int,int > >& points) {
    vector< pair<int,int > > convexhull;
    
    std::sort(points.begin(), points.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    pair<int,int> lowest = points[0];
    convexhull.push_back(lowest);
    std::sort(points.begin(), points.end(), [lowest](auto &left, auto &right) {
        return  atan2 ((left.second - lowest.second),(left.first - lowest.first)) <
            atan2 ((right.second - lowest.second),(right.first - lowest.first));
    }); 
    convexhull.push_back(points[1]);

    for(int i = 2; i < points.size(); i++) {
        pair<int,int> last = convexhull[convexhull.size()-1];
        convexhull.pop_back();
        while(Clockwise(convexhull[convexhull.size()-1], last, points[i]))
        {
            last = convexhull[convexhull.size()-1];
            convexhull.pop_back();
        } 
        convexhull.push_back(last);
        convexhull.push_back(points[i]);
    }
    return convexhull;
}


int main() {
    vector< pair<int,int > > points;

    int x,y;
    char comma;
    while(true)
    {
        string input;
        getline(cin, input);
        if( !cin ) break;
        if (input.empty())
        {
            vector<pair<int,int> > hull =  ConvexHull(points);
            cout << hull.size() << endl;
            for( auto p: hull) {
                //cout << p.first << ", " << p.second << endl;
            }
            cout << endl;
            points.clear();
            continue;
        }
        stringstream ss(input);
        ss >> x >> comma >> y;
        points.emplace_back(make_pair(x,y));
    }

    
}

