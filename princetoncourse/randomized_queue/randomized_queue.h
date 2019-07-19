#include <iostream> 
#include <unordered_set>
#include <ctime>

using namespace std;

template <class T> 
class RandomizedQueue {
private:
    int n;
    T* queue;
    int arraySize;
    unordered_set<int> empty_spaces;

    void resizeArray(int length)
    {
        T* newQueue = new T[length];
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(empty_spaces.find(i) == empty_spaces.end())
                newQueue[j++] = queue[i]; 
        }
        n = Size();
        delete [] queue;
        queue = newQueue;
        arraySize = length;
    }


public:
    class Iterator;

    // construct an empty randomized queue
    RandomizedQueue(): n(0), arraySize(4) {
        queue = new T[4];
        srand(time(0));
    }

    // is the randomized queue empty?
    bool IsEmpty() {
        return n == 0;
    }

    // return the number of items on the randomized queue
    int Size() {
        return n - empty_spaces.size();
    }

    // add the item
    void Enqueue(T item) {
        if(n == arraySize)
            resizeArray(arraySize*2);
        queue[n++] = item;
    }

    // remove and return a random item
    T Dequeue() {
        if(IsEmpty())
            throw "no elements in the queue";
        int i;
        do 
        {
            i = rand() % n;
        } while(empty_spaces.find(i) != empty_spaces.end());
        empty_spaces.insert(i);
        if (!IsEmpty() && Size() == arraySize / 4)
        {
            resizeArray(arraySize/2);
        }
        return queue[i];
    }

    // return a random item (but do not remove it)
    T Sample() {
        if(IsEmpty())
            throw "no elements in the queue";
        int i;
        do 
        {
            i = rand() % n;
        } while(empty_spaces.find(i) != empty_spaces.end());
        return queue[i];
        
    }

    Iterator begin() { 
        return Iterator(queue, empty_spaces); 
    } 
  
    Iterator end() { 
        return Iterator(n, queue, empty_spaces); 
    } 

    class Iterator { 
    public: 
        Iterator(int* queue, unordered_set<int>& empty_spaces)  : index (0), queue(queue), empty_spaces(empty_spaces) {
            while(empty_spaces.find(this->index) != empty_spaces.end())
            {
                this->index++; 
            } 
        }
    
        Iterator(int n, int* queue, unordered_set<int>& empty_spaces) : index (n), queue(queue), empty_spaces(empty_spaces)  { } 
    
        Iterator& operator=(int index) { 
            this->index = index; 
            return *this; 
        } 

        Iterator& operator++() {
            do 
            {
                this->index++; 
            } while(empty_spaces.find(this->index) != empty_spaces.end());
            return *this; 
        } 

        Iterator operator++(int) { 
            ++*this; 
            return *this; 
        } 

        bool operator!=(const Iterator& iterator) { 
            return index != iterator.index; 
        } 

        int operator*() { 
            return queue[index]; 
        } 

    private: 
        int index; 
        int* queue;
        unordered_set<int> empty_spaces;
    }; 

};