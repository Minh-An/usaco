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
    ifstream ifs("revegetate.in", ifstream::in);
    ofstream ofs("revegetate.out", ofstream::out);

    unordered_map<int, unordered_set<int>> pastures;
    
    int n, m;
    ifs >> n, m;

    for (int i = 0; i < m; i++)
    {
        int a,b;
        ifs >> a >> b;
        pastures[a].emplace(b);
        pastures[b].emplace(a);
    }

    vector<int> answer(n);

    for(int i = 1; i <= n; i++)
    {   
        unordered_set<int>  taken_seeds;
        for(int k = 1; k < i; k++)
        {
            if(pastures[i].find(k) != pastures[i].end())
            {
                taken_seeds.emplace(answer[k]);
            }
        }
        for(int j = 1; i <= 4; i++)
        {   
            if(taken_seeds.find(j) == taken_seeds.end())
            {
                ofs << j;
                break;
            }
        }
    }
    ofs << endl;
}
