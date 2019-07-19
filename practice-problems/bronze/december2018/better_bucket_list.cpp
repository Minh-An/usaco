#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
An O(nlogn) time algorithm for USACO's The Bucket List Problem
2018 December Bronze Problem
 */

int main(int argc, char const *argv[])
{
    uint32_t n;

    ifstream ifs(argv[1], ifstream::in);
    //ifstream ifs("blist.in", ifstream::in);
    ifs >> n;

    vector<pair<uint32_t, uint32_t>> buckets_at_time(2 * n);

    for(int i = 0; i < 2*n; i+=2)
    {
        ifs >> buckets_at_time[i].first;
        ifs >> buckets_at_time[i+1].first;
        ifs >> buckets_at_time[i].second;        
        buckets_at_time[i+1].second = -buckets_at_time[i].second;
    }

    sort(buckets_at_time.begin(), buckets_at_time.end());
   
    uint32_t max_buckets = 0;
    uint32_t current_buckets = 0;
    for(pair<uint32_t, uint32_t> time_buckets: buckets_at_time)
    {
        current_buckets += time_buckets.second;
        if (current_buckets > max_buckets)
        {
            max_buckets = current_buckets;
        }
    }

    ofstream ofs("blist.out", ofstream::out);
    ofs << max_buckets << endl;
}
