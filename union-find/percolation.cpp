#include "percolation.h"
#include <iostream>

Percolation::Percolation(int n): n{n}, uf{UnionFind(n*n+2)} {
    //+2 for the top and bottom virtual nodes
    //connect virtual nodes
    for(int i =0; i < n; i++) {
        uf.Union(n, i); //connect top virtual node to top row
        uf.Union(n+1, n*n-1-i); //connect bottom virtual node to bottom row
    }
}
void Percolation::Open(int r, int c) {
    if (r <= 0 || c <= 0 || r > n || c > n) 
    {
        //throw exception
    }
    open.insert(toOneD(r,c));
    int oneD = toOneD(r,c);
    if ( c < n &&  IsOpen(r, c+1)) { uf.Union(oneD+1, oneD);} //right
    if ( c > 1 && IsOpen(r, c-1)) { uf.Union(oneD - 1, oneD);} //left
    if ( r < n && IsOpen(r+1, c)) { uf.Union(oneD + n, oneD);} //down
    if (r > 1 && IsOpen(r-1, c)) { uf.Union(oneD - n, oneD);} // up
    //add connections to adj squares
}
bool Percolation::IsOpen(int r, int c) {
    return open.find(toOneD(r,c)) != open.end();
}

bool Percolation::IsFull(int r, int c) {
    return uf.Connected(toOneD(r,c), n);
}

int Percolation::NumberOfOpenSites() {
    return open.size();
}
bool Percolation::Percolates() {
    return uf.Connected(n+1, n);
}
int Percolation::toOneD(int r, int c) {
    return (r-1) * n + (c-1);
}


