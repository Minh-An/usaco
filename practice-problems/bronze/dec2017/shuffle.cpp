#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //ifstream ifs(argv[1], ifstream::in);
    ifstream ifs("shuffle.in", ifstream::in);
    ofstream ofs("shuffle.out", ofstream::out);

    int n; 
    ifs >> n;

    vector<int> a(n);
    for(int i = 0 ; i < n; i++)
    {
        ifs >> a[i];
    }

    vector<int> ids(n);
    for(int i = 0 ; i < n; i++)
    {
        ifs >> ids[i];
    }


    for(int i = n-1; i >= 0; i--)
    {
        iter_swap(ids.begin() + a[i]-1, ids.begin() + i);
    }

    for(int id: ids)
    {
        ofs << id << endl;
    }
}
