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
    ifstream ifs("herding.in", ifstream::in);
    ofstream ofs("herding.out", ofstream::out);
    int b, e, m;
    ifs >> b >> e >> m;

    int max_cow = max(b, max(e,m));
    int min_cow = min(b, min(e,m));

    int median_cow = max(min(b, e), min(max(b, e), m));

    int max_moves = max(max_cow-median_cow, median_cow-min_cow) - 1 ;
    int min_moves;

    if(max_moves == 0) min_moves = 0;
    else if(max_cow - median_cow == 2 || median_cow - max_cow == 2) min_moves = 1;
    else min_moves = 2;

    ofs << min_moves << endl;
    ofs << max_moves << endl;

}
