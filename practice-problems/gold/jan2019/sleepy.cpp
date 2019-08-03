#include <fstream>
#include <vector>
#include <set>
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
    ifstream ifs(argv[1], ifstream::in);
    //ifstream ifs("sleepy.in", ifstream::in);
    ofstream ofs("sleepy.out", ofstream::out);
    int n;
    ifs >> n;

    vector<int> cows(n);

    for(int i = 0; i < n; i++)
    {
        ifs >> cows[i];
    }

    int index = 0;
    for(int i = n-1; i > 0; i--)
    {
        if (cows[i-1] > cows[i])
        {
            index = i;
            break;
        }
    }
    ofs << index << endl;

    set<int> sorted(cows.begin()+index, cows.end());
    cout << index << endl;

    int index2 = index;
    for(int i = 0; i < index; i++)
    {
        pair<set<int>::iterator, bool> p = sorted.emplace(cows[i]);
        int k = distance(sorted.begin(), p.first);
        ofs << k + --index2;
        if(i != index-1) ofs << " ";
    }
    ofs << endl;
}