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
    ifstream ifs("sleepy.in", ifstream::in);
    ofstream ofs("sleepy.out", ofstream::out);
    int n;
    ifs >> n;

    vector<int> cows(n);

    for(int i = 0; i < n; i++)
    {
        ifs >> cows[i];
    }

    for(int i = n-1; i > 0; i--)
    {
        if (cows[i-1] > cows[i])
        {
            ofs << i << endl;
            return 0;
        }
    }
    ofs << 0 << endl;
}