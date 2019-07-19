#include <set>
#include "union_find.h"

using namespace std;

class Percolation {
    public:
        Percolation(int n);
        void Open(int r, int c);
        bool IsOpen(int r, int c);
        bool IsFull(int r, int c);
        int NumberOfOpenSites();
        bool Percolates();
    private:
        UnionFind uf;
        int n;
        int opensites;

        set<int> open;

        int toOneD(int r, int c);
};