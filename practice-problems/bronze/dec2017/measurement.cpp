#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    //ifstream ifs(argv[1], ifstream::in);
    ifstream ifs("measurement.in", ifstream::in);
    ofstream ofs("measurement.out", ofstream::out);

    int n; 
    ifs >> n;
    

    vector<int> display{0,1,2};
    int changes = 0;
    vector<int> cows(3, 7);

    map<int, pair<int,int>> recordings;
    for(int i = 0 ; i < n; i++)
    {
        int date;
        string cow, change;
        ifs >> date >> cow >> change;
        bool positive = change[0] == '+';
        int num = change[1] - '0';
        int cow_num = cow == "Bessie" ? 0 : (cow == "Elsie" ? 1 : 2);
        recordings.emplace(date, make_pair(cow_num, positive ? num : -num));
    }

    vector<int> local_max;
    for(pair<int, pair<int,int>> recording: recordings) {
        local_max.clear();
        cows[recording.second.first] += recording.second.second;
        int max = *max_element(cows.begin(), cows.end());
        for(int i = 0; i < 3; i++)
        {
            if (cows[i] == max) local_max.push_back(i);
        }
        if (local_max != display) 
        {
            changes++;
            display = local_max;
            
        }
    }

    ofs << changes << endl;
}