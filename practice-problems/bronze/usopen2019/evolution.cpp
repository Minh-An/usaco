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
    ifstream ifs("evolution.in", ifstream::in);
    ofstream ofs("evolution.out", ofstream::out);
    int subpopulations;
    ifs >> subpopulations;

    unordered_map<string, vector<string>> evolutionary_tree;
    evolutionary_tree["base"] = vector<string>();


    for(int i = 0; i < subpopulations; i++)
    {
        int n; 
        ifs >> n;
        vector<string> traits(n);
        for (int j = 0; j < n; j++)
        {
            ifs >> traits[j];
        }
        string current = "base";
        while(!traits.empty())
        {
            string prev = current;
            for(string trait: traits)
            {
                vector<string> children = evolutionary_tree[current];
                if (find(children.begin(), children.end(), trait) != children.end())
                {
                    current = trait;
                    break;
                } 
            }
            if (current.compare(prev) == 0)
            {
                
                if(evolutionary_tree.find(traits[0]) != evolutionary_tree.end())
                {
                    ofs << "no" << endl;
                    return 0; 
                }
                evolutionary_tree[current] = vector<string>();
                evolutionary_tree[current].push_back(traits[0]);
                current = traits[0];
            }
            traits.erase(find(traits.begin(), traits.end(), current));
        }
    }
    ofs << "yes" << endl;
}