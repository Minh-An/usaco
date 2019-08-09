#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool valid_wait(vector<int>& cow_trips, int wait_time, int m, int c)
{
    int trips = 1; 
    int firstIndex = 0;
    for(int i = 0; i < cow_trips.size(); i++)
    {
        if(cow_trips[i] - cow_trips[firstIndex] > wait_time || i+1 - firstIndex > c)
        {
            trips += 1;
            firstIndex = i;
        }
    }
    return trips <= m;
}

int binary_search(vector<int>& cow_trips, int lo, int hi, int m, int c)
{
    int mid = lo + (hi-lo)/2;
    if(lo >= hi)
    {
        return lo;
    }
    if(valid_wait(cow_trips, mid, m, c)) return binary_search(cow_trips, lo, mid, m,c);
    else return binary_search(cow_trips, mid+1, hi, m, c);
}

int main(int argc, char const *argv[])
{
    ifstream ifs(argv[1], ifstream::in);
    //ifstream ifs("convention.in", ifstream::in);
    ofstream ofs("convention.out", ofstream::out);

    int n,m,c;

    ifs >> n >> m >> c;

    vector<int> cow_times(n);

    for(int i = 0; i < n; i++)
    {
        int time;
        ifs >> time;
        cow_times[i]=time;
    }

    sort(cow_times.begin(), cow_times.end());


    vector<int> time_diffs;
    time_diffs.reserve(n-1);

    int prev = -1;
    for(int time: cow_times)
    {
        if(prev != -1) 
        {
            time_diffs.push_back(time-prev);
        }
        prev = time;
    }

    int index = binary_search(cow_times, 0, *max_element(time_diffs.begin(), time_diffs.end()), m, c);

    ofs << index;
}

