#include <iostream>
#include <vector>
#include <functional>

using namespace std;


template <class T>
void merge(vector<T>& a, vector<T>& aux, int lo, int mid, int hi, function<bool(const T&,const T&)> func)
{
    for(int i = lo; i < hi; i++)
    {
        aux[i] = a[i];
    }

    int i = lo; int j = mid+1;
    for(int k = lo; k < hi; k++)
    {
        if (i > mid) 
            a[k] = aux[j++];
        else if (j == hi) 
            a[k] = aux[i++];
        else if (func(aux[j], aux[i])) 
            a[k] = aux[j++];
        else 
            a[k] = aux[i++];
    }
}


template <class T>
void sort(vector<T>& a, function<bool(const T&,const T&)> func)
{
    int N = a.size();
    vector<T> aux(N);
    for (int k = 1; k < N; k *= 2)
    {
        for(int i = 0; i < N-k; i+= 2*k)
        {
            merge(a, aux, i, i+k-1, min(i+(2*k), N), func);
        }
    }
}


int main(int argc, char const *argv[])
{
    vector<int> ints{1,7,9,2,5,3,6,4,8};
    sort<int>(ints, less<int>());

    for (int i: ints) {
        cout << i << " ";
    }
    cout << endl;
}
