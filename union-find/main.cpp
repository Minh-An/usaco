#include <fstream>
#include <iostream>
#include "union_find.h"
#include <ctime>

int main(int argc, char const *argv[])
{
    vector <int> pdata(2000000);
    vector <int> qdata(2000000);
    ifstream ifs("large.txt", ifstream::in);
    int n;
    ifs >> n;
    
    UnionFind uf = UnionFind(n);

    int i = 0;
    while(!ifs.eof())
    {
        int p, q; 
        ifs >> pdata[i];
        ifs >> qdata[i++];
        
        //cout << p << " " << q << endl;
    }

    clock_t begin = clock();
    for(int i = 0; i < pdata.size(); i++) {
        if (uf.Connected(pdata[i],qdata[i])) { continue; }
        uf.Union(pdata[i],qdata[i]);
    }
    clock_t endt = clock();
    cout << (endt-begin) * 1000 / CLOCKS_PER_SEC << "ms" << endl; //283ms
    cout << uf.Count() << " components" << endl;
}