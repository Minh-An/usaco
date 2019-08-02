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
    ifstream ifs("guess.in", ifstream::in);
    ofstream ofs("guess.out", ofstream::out);
    int n;
    ifs >> n;

    unordered_map<string, unordered_set<string>> animals;

    for(int i = 0; i < n; i++)
    {
        int traits;
        string name;
        ifs >> name >> traits;
        animals[name] = unordered_set<string>();
        for(int j = 0; j < traits; j++)
        {
            string trait;
            ifs >> trait;
            animals[name].emplace(trait);
        }
    }

    int max = 1;
    for(pair<string, unordered_set<string>> animal: animals)
    {
        for(pair<string, unordered_set<string>> compare: animals)
        {
            int non_unique_traits = 0;
            if(compare.first == animal.first) continue;
            for(string trait: animal.second)
            {
                if(compare.second.find(trait) != compare.second.end()) {
                    non_unique_traits++;
                }
            }
            if(non_unique_traits < animal.second.size() && non_unique_traits >= max)
            {
                max = non_unique_traits+1;
            }
        }
    }
    

    ofs << max << endl;
}