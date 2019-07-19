#include <iostream>
#include <ctime>
#include "percolation_stats.h"

int main(int argc, char const *argv[])
{
    PercolationStats ps = PercolationStats(100, 100);
    cout << "mean: " << ps.Mean() << " with confidence intervals " << ps.ConfidenceLo() << " - " << ps.ConfidenceHi() << endl;
}