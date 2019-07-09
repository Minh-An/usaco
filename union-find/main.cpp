#include <fstream>
#include <iostream>
#include "union_find.h"
#include <ctime>

int main(int argc, char const *argv[])
{
    
    ifstream ifs("large.txt", ifstream::in);
    int n;
    ifs >> n;
    
    UnionFind uf = UnionFind(n);

    clock_t begin = clock();
    while(ifs.eof() == false)
    {
        int p, q; 
        ifs >> p;
        ifs >> q;
        if (uf.Connected(p,q)) { continue; }
        uf.Union(p,q);
        //cout << p << " " << q << endl;
    }
    clock_t endt = clock();
    cout << (endt-begin) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    cout << uf.Count() << " components" << endl;
}