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
    pair<pair<int,int>, pair<int,int>> truck;
    ifs >> truck.first.first >> truck.second.first >>  truck.first.second >> truck.second.second;


    int remaining = (billboard1.first.second - billboard1.first.first) * (billboard1.second.second - billboard1.second.first);
    remaining += (billboard2.first.second - billboard2.first.first) * (billboard2.second.second - billboard2.second.first);

    int overlap_x = min(truck.first.second, billboard1.first.second) - max(truck.first.first, billboard1.first.first);
    int overlap_y = min(truck.second.second, billboard1.second.second) - max(truck.second.first, billboard1.second.first);
    remaining -= overlap_x*overlap_y;

    overlap_x = min(truck.first.second, billboard2.first.second) - max(truck.first.first, billboard2.first.first);
    overlap_y = min(truck.second.second, billboard2.second.second) - max(truck.second.first, billboard2.second.first);
    remaining -= overlap_x*overlap_y;

    ofs << remaining << endl;
}