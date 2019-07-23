#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
#include <math.h> 
#include <numeric>

using namespace std;

int Orientation(const pair<int,int>& a, const pair<int,int>& b, const pair<int,int>& c)
{
    int area2 = (b.first-a.first) * (c.second - a.second) - (b.second - a.second)*(c.first-a.first);
    if (area2 > 0) return 1;
    return area2 < 0 ? -1: 0;
}

void ConvexHull(vector< pair<int,int > >& points) {

    vector< pair<int,int > > convexhull;
    
    vector<pair<int,int >> original(points);

    std::sort(points.begin(), points.end(), [](const pair<int,int>  &left, const pair<int,int>  &right) {
        return left.second < right.second;
    });

    pair<int,int> lowest = points[0];
    std::sort(points.begin(), points.end(), [lowest](const pair<int,int> &left, const pair<int,int> &right) {
        return  atan2 ((left.second - lowest.second),(left.first -  lowest.first)) <
            atan2 ((right.second -  lowest.second),(right.first -  lowest.first));
    });

    convexhull.push_back(points[0]);
    int k, j;

    for (k = 1; k < points.size(); k++)
        if (points[0] != points[k]) break;
    if (k == points.size()) return;
    convexhull.push_back(points[k]);

    for (j = k+1; j < points.size(); j++)
        if (Orientation(points[0], points[k], points[j]) != 0) break;
    convexhull.push_back(points[j-1]);


    for(int i = j; i < points.size(); i++) {
        pair<int,int> last = convexhull.back();
        convexhull.pop_back();
        while(!convexhull.empty() && Orientation(convexhull.back(), last, points[i]) <= 0)
        {
            last = convexhull.back();
            convexhull.pop_back();
        } 
        convexhull.push_back(last);
        convexhull.push_back(points[i]);
    }

    vector<pair<int,int>>::iterator it;
    for (pair<int,int> p: original) 
    {
        it = find(convexhull.begin(), convexhull.end(), p);
        if (it != convexhull.end())
            break;
    }

    std::rotate(convexhull.begin(),it,convexhull.end());
    convexhull.push_back(convexhull[0]);

    for( pair<int,int> p: convexhull) {
        cout << p.first << ", " << p.second << endl;
    }
    cout << endl;

}



int main() {
    vector< pair<int,int > > points;

    int x,y;
    char comma;
    while(true)
    {
        string input;
        getline(cin, input);
        if( !cin ) 
        {
            break;
        }
        if (input.empty())
        {
            ConvexHull(points);
            points.clear();
            continue;
        }
        stringstream ss(input);
        ss >> x >> comma >> y;
        points.emplace_back(make_pair(x,y));
    }
    ConvexHull(points);
    
}