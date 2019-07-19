#include <vector>
#include <numeric>
#include <cmath>
#include "percolation.h"
#include <iostream>
#include <random>

class PercolationStats {
    public:
        PercolationStats(int n, int trials): percolation{Percolation(n)} {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<> dist(1, n);
            ps = vector<double>(trials);
            for (int t= 0; t < trials; t++)
            {
                percolation = Percolation(n);
                while(!percolation.Percolates()){
                    //open random open site
                    int r = dist(mt);
                    int c = dist(mt);
                    while (percolation.IsOpen(r,c)) { 
                        r = dist(mt);
                        c = dist(mt);
                    }
                    percolation.Open(r, c);
                }
                ps[t] = double(percolation.NumberOfOpenSites())/double(n*n);
            }
            cout << endl;
        }

        // sample mean of percolation threshold
        double Mean() {
            double sum = accumulate(ps.begin(), ps.end(), 0.0);

            return sum / ps.size();
        }

        // sample standard deviation of percolation threshold
        double Stddev() {
            double mean = Mean();
            auto lambda = [&](double a, double b){return a + pow(b - mean, 2.0); };
            double sum = accumulate(ps.begin(), ps.end(), 0.0, lambda);
            return sqrt(sum/(ps.size()-1));
        }
        // low endpoint of 95% confidence interval
        double ConfidenceLo() {
            return Mean() - (1.96*Stddev()/sqrt(ps.size()));
        } 

        // high endpoint of 95% confidence interval
        double ConfidenceHi() {
            return Mean() + (1.96*Stddev()/sqrt(ps.size()));
        }

    private:
        Percolation percolation;
        vector<double> ps;
};