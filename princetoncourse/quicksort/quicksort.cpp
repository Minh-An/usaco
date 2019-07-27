#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
int partition(vector<T>& a, function<bool(const T&,const T&)> less, int lo, int hi) {
    int i = lo; int j = hi + 1;
    while(i < j)
    {
        while(less(a[++i],a[lo]))
        {
            if(i == hi) break;
        }
        while(less(a[lo],a[--j]))
        {
            if(j == lo) break;
        }
        if(i >= j) break;
        iter_swap(a.begin() + i, a.begin() + j);
    }
    iter_swap(a.begin() + lo, a.begin() + j);
    return j;
}


template <class T>
void quicksort(vector<T>& a, function<bool(const T&,const T&)> less, int lo, int hi) {
    if(hi <= lo) return;
    int index = partition(a, less, lo, hi);
    quicksort(a, less, lo, index-1);
    quicksort(a, less, index + 1, hi);
}


template <class T>
void quicksort(vector<T>& a, function<bool(const T&,const T&)> less) {
    random_shuffle(a.begin(), a.end());
    quicksort(a, less, 0, a.size()-1);
}


int main(int argc, char const *argv[])
{
    vector<int> ints{1,7,9,2,5,3,6,4,8};
    quicksort<int>(ints, less<int>());

    for (int i: ints) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


