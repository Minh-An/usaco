#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

template <class T>
pair<int, int> partition(vector<T>& a, function<bool(const T&,const T&)> less, int lo, int hi) {
    int i = lo;
    int lt = lo;
    int gt = hi;
    T v = a[lo];
    while(i <= gt)
    {
        if(less(a[i], v)) {
            iter_swap(a.begin() + i++, a.begin() + lt++);
        }
        else if(less(v, a[i])) {
            iter_swap(a.begin() + i, a.begin() + gt--);
        }
        else {
            i++;
        }   
    }
    return make_pair(lt, gt);
}


template <class T>
void quicksort(vector<T>& a, function<bool(const T&,const T&)> less, int lo, int hi) {
    if(hi <= lo) return;
    pair<int,int> middle = partition(a, less, lo, hi);
    quicksort(a, less, lo, middle.first-1);
    quicksort(a, less, middle.second + 1, hi);
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
}


