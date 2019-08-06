#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //ifstream ifs(argv[1], ifstream::in);
    ifstream ifs("traffic.in", ifstream::in);
    ofstream ofs("traffic.out", ofstream::out);

    pair<int, int> current_range{0,0};

    vector<pair<int,int>> ons_offs;
    
    int n;
    ifs >> n;

    int nones = 0;

    for (int i = 0; i < n; i++)
    {
        string type;
        int a,b;
        ifs >> type >> a >> b;
        if(type == "none")
        {
            if(nones == 0) current_range = make_pair(a,b);
            current_range = make_pair(max(current_range.first, a), min(current_range.second, b));
            nones++;
        }
        else if (type == "off")
        {
            current_range = make_pair(current_range.first-b, current_range.second-a);
            ons_offs.push_back(make_pair(a,b));
        }
        else { // "on"
            current_range = make_pair(current_range.first+a, current_range.second+b);
            ons_offs.push_back(make_pair(-a,-b));
        }
    }
    ofs << current_range.first << " " << current_range.second << endl;


    for(pair<int,int> p: ons_offs)
    {
        current_range  = make_pair(current_range.first+p.second, current_range.second+p.first);
    }
    ofs << current_range.first << " " << current_range.second << endl;
}