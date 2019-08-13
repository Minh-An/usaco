#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    //ifstream ifs(argv[1], ifstream::in);
    ifstream ifs("lifeguard.in", ifstream::in);
    ofstream ofs("lifeguard.out", ofstream::out);

    int n; 
    ifs >> n;

    vector<pair<int,int>> cow_times(n);
    for(int i = 0 ; i < n; i++)
    {
        ifs >> cow_times[i].first >> cow_times[i].second;
    }

    int max = 0;
    set<int> range;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if (j == i) continue;
            for(int k = cow_times[j].first; k < cow_times[j].second; k++)
            {
                range.emplace(k);
            }
        }
        if (range.size() > max) max = range.size();
        range.clear();
    }

    ofs << max << endl;
}