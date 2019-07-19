#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    uint32_t buckets = 3;
    vector<uint32_t> capacities(buckets);
    vector<uint32_t> milk(buckets);

    //ifstream ifs(argv[1], ifstream::in);
    ifstream ifs("mixmilk.in", ifstream::in);
    uint32_t b = 0;
    while(!ifs.eof())
    {
        ifs >> capacities[b];
        ifs >> milk[b++];
    }

    b = 0;
    for(uint32_t i = 0; i < 100; i++)
    {
        uint32_t next =(b+1)%3;
        uint32_t amount = min(milk[b], capacities[next]-milk[next]);
        milk[b] -= amount;
        milk[next] += amount;
        b = next;
    }

    ofstream ofs("mixmilk.out", ofstream::out);
    for(b = 0; b < buckets; b++)
    {
        ofs << milk[b] << endl;
    }
}
