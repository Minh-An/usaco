#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    //ifstream ifs(argv[1], ifstream::in);
    ifstream ifs("billboard.in", ifstream::in);
    ofstream ofs("billboard.out", ofstream::out);

    pair<pair<int,int>, pair<int,int>> billboard1;
    ifs >> billboard1.first.first >> billboard1.second.first >>  billboard1.first.second >> billboard1.second.second;
    pair<pair<int,int>, pair<int,int>> billboard2;
    ifs >> billboard2.first.first >> billboard2.second.first >>  billboard2.first.second >> billboard2.second.second;

    int overlap_x = min(billboard2.first.second, billboard1.first.second) - max(billboard2.first.first, billboard1.first.first);
    int overlap_y = min(billboard2.second.second, billboard1.second.second) - max(billboard2.second.first, billboard1.second.first);
    
    int tarp_y = (billboard1.second.second - billboard1.second.first);
    int tarp_x = billboard1.first.second - billboard1.first.first;
    
    if (overlap_x == billboard1.first.second - billboard1.first.first) {
        tarp_y -= overlap_y;
    }

    if (overlap_y == billboard1.second.second - billboard1.second.first) {
        tarp_x -= overlap_x;
    }

    ofs << tarp_x*tarp_y << endl;
}