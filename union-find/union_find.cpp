#include "union_find.h"

UnionFind::UnionFind(int n): n{n}  {
    id = vector<int>(n);
    sz = vector<int>(n);
    for(int i = 0; i < n; i++) {
        id[i] = i;
        sz[i] = 1;
    }

}

int UnionFind::root(int p) {
    while(p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

bool UnionFind::Connected(int p, int q) {
    return root(p) == root(q);
}

void UnionFind::Union(int p, int q) {
    int rp = root(p);
    int rq = root(q);
    if(rp == rq) { return; }
    if (sz[rp] < sz[rq]) {
        id[rp] = rq;
        sz[rq] += sz[rp]; 
        return;
    }
    id[rq] = rp;
    sz[rp] += sz[rq]; 
}