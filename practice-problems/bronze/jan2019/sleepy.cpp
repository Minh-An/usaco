#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void shift(vector<int>& cows, int a, int b)
{
    for(int i = a; i < b; i ++)
    {
        iter_swap(cows.begin()+i, cows.begin()+i+1);
    }
}


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

    if(is_sorted(cows.begin(), cows.end()))
    {
        ofs << 0 << endl;
        return 0;
    }

    int time_stamps = 0;

    vector<int> cows_copy(cows);
    int j;

    while(!is_sorted(cows.begin(), cows.end()))
    {
        for(j = 1; j < n; j++)
        {
            if (is_sorted(cows.begin()+j, cows.end()))
            {
                for(int k = j; k < n; k++)
                {
                    if(cows[0] < cows[k])
                    {
                        shift(cows, 0, k-1);
                        break;
                    }
                    if(k == n-1)
                    {
                        shift(cows, 0, k);
                    }
                }
                --j;
                break;
            }
        }
        time_stamps++;
    }
    


    while(!is_sorted(cows.begin(), cows.end()))
    {
        for(int k = j; k < n; k++)
        {
            if(cows[0] < cows[k])
            {
                shift(cows, 0, k-1);
                j--;
                break;
            }
            if(k == n-1)
            {
                shift(cows, 0, k);
            }
        }
        time_stamps++;
        for(int i: cows)
        {
            cout << i << ",";
        }
        cout << endl;
    }

    ofs << time_stamps << endl;
}


