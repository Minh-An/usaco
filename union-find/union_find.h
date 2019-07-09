#include <vector>

using namespace std;
class UnionFind {
    public:
        UnionFind(int n);
        void Union(int p, int q);
        bool Connected(int p, int q);
    private:
        int n;
        vector<int> id;  
        vector<int> sz;  

        int root(int p);
};