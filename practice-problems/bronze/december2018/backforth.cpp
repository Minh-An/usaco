#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

int main(int argc, char const *argv[])
{
    //fstream ifs(argv[1], ifstream::in);
    ifstream ifs("backforth.in", ifstream::in);

    vector<int> buckets1(10);
    vector<int> buckets2(10);

    for(int i = 0; i < 10; i++)
    {
        ifs >> buckets1[i];
    }
    for(int i = 0; i < 10; i++)
    {
        ifs >> buckets2[i];
    }

    set<int> tank_readings;

    for(int i = 0; i < buckets1.size(); i++)
    {
        int tuesday = buckets1[i];
        vector<int> wed = buckets2;
        wed.push_back(tuesday);
        for(int j = 0; j < wed.size(); j++)
        {
            int wednesday = wed[j];
            vector<int> thur = buckets1;
            thur.erase(thur.begin()+i);
            thur.push_back(wednesday);
            for(int thursday: thur)
            {
                vector<int> fri = wed;
                fri.erase(fri.begin()+j);
                fri.push_back(thursday);
                for(int friday: fri)
                {
                    //cout << tuesday << " " << wednesday << " " << thursday << " " << friday << " " << friday+wednesday - tuesday - thursday << endl;
                    tank_readings.insert(friday+wednesday - tuesday - thursday);
                }
            }
        }
    }

    /* for(int reading: tank_readings)
    {
        cout << reading << " ";
    }
    cout << endl;*/

    ofstream ofs("backforth.out", ofstream::out);
    ofs << tank_readings.size() << endl;
}
