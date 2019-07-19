#include <iostream> 
using namespace std;

template <class T> 
class Deque {
private: 
    class Node 
    { 
        T val; 
        Node* next; 
        Node* prev;

        friend class Deque; 

        Node(T val) 
        { 
            this->val = val; 
            next = nullptr; 
            prev = nullptr;
        } 
    }; 
  
    Node* head;
    Node* tail; 
    int n;

public:

    class Iterator;

    // construct an empty deque
    Deque(): n{0} {
        head = nullptr;
        tail = nullptr;
    }

    // is the deque empty?
    bool IsEmpty() {
        return n == 0;
    }

    // return the number of items on the deque
    int Size() {
        return n;
    }

    // add the item to the front
    void AddFirst(T item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        if(++n == 1)
            tail = newNode;
        else
            head->prev = newNode;
        head = newNode;
    }

    // add the item to the back
    void AddLast(T item) {
        Node* newNode = new Node(item);
        newNode->prev = tail;
        if(++n == 1)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        
    }

    // remove and return the item from the front
    T RemoveFirst() {
        if (IsEmpty())
            throw "cannot remove from an empty deque";
        Node* oldHead = head;
        head = head->next;
        if(head != nullptr)
            head->prev = nullptr;
        T item = oldHead->val;
        delete oldHead;
        n--;
        return item;
    }

    // remove and return the item from the back
    T RemoveLast() {
        if (IsEmpty())
            throw "cannot remove from an empty deque";
        Node* oldTail = tail;
        tail = tail->prev;
        if(head != nullptr)
            tail->next = nullptr;
        T item = oldTail->val;
        delete oldTail;
        n--;
        return item;
    }

    Iterator begin() 
    { 
        return Iterator(head); 
    } 
  
    Iterator end() 
    { 
        return Iterator(nullptr); 
    } 

    class Iterator { 
    public: 
        //Iterator()  : currentNode (head) { }
    
        Iterator(const Node* node) : currentNode (node) { } 
    
        Iterator& operator=(Node* node) 
        { 
            this->currentNode = node; 
            return *this; 
        } 

        Iterator& operator++() 
        {
            if (currentNode) 
                currentNode = currentNode->next; 
            return *this; 
        } 

        Iterator operator++(int) 
        { 
            if (currentNode) 
                currentNode = currentNode->next; 
            return *this; 
        } 

        bool operator!=(const Iterator& iterator) 
        { 
            return currentNode != iterator.currentNode; 
        } 

        int operator*() 
        { 
            return currentNode->val; 
        } 

    private: 
        const Node* currentNode; 
    }; 
}; 