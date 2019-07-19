#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    uint32_t n;

    ifstream ifs(argv[1], ifstream::in);
    //ifstream ifs("blist.in", ifstream::in);
    ifs >> n;

    vector<uint32_t> start_times(n);
    vector<uint32_t> end_times(n);
    vector<uint32_t> buckets_used(n);

    for(int i = 0; i < n; i++)
    {
        ifs >> start_times[i];
        ifs >> end_times[i];
        ifs >> buckets_used[i];
    }


   
    uint32_t max_buckets = 0;
    /* 
    OLD CODE: Checking EVERY possible timestamp for max buckets  
    uint32_t max_time = *max_element(end_times.begin(), end_times.end());
    uint32_t min_time = *min_element(start_times.begin(), start_times.end());
    for(uint32_t time = min_time; time <= max_time; time++)
    */

    // OPTIMIZED: Checking only start and end times of cows -> the only significant timestamps -> same result 
    // n = # of cows, m = # of timestamps 
    // O(nm) -> O(n^2)
    // 100,000 -> 10,000
    start_times.insert(start_times.end(), end_times.begin(), end_times.end());
    for(uint32_t time: start_times)
    {
        uint16_t buckets = 0;
        for(int i = 0; i < n; i++) 
        {
            if (time >= start_times[i] && time <= end_times[i])
            {
                buckets += buckets_used[i];
            }
        }
        if(buckets > max_buckets)
        {
            max_buckets = buckets;
        }
    }

    ofstream ofs("blist.out", ofstream::out);
    ofs << max_buckets << endl;
}
