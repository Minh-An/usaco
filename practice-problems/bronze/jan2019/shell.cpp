#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //ifstream ifs(argv[1], ifstream::in);
    ifstream ifs("shell.in", ifstream::in);
    ofstream ofs("shell.out", ofstream::out);
    int n;
    ifs >> n;

    vector<pair<int,int>> swaps(n);
    vector<int> guesses(n);


    for(int i = 0; i < n; i++)
    {
        int b1, b2;
        ifs >> b1;
        ifs >> b2;
        swaps[i] = make_pair(b1,b2);
        ifs >> guesses[i];
    }

    int max = 0;

    for (int i = 1; i <= 3; i++)
    {
        int pebble = i; 
        int points = 0;
        for(int j = 0; j < n; j++ )
        {
            if(pebble == swaps[j].first)
            {
                pebble = swaps[j].second;
            }
            else if(pebble == swaps[j].second)
            {
                pebble = swaps[j].first;
            }
            if(guesses[j] == pebble)
            {
                points++;
            }
        }
        if(points > max)
        {
            max = points;
        }
    }

    ofs << max << endl;
}