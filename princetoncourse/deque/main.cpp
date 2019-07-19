#include "deque.h"

int main(int argc, char const *argv[])
{
    Deque<int> deque = Deque<int>();
    for (int i = 1; i <= 5; i++)
    {
        deque.AddFirst(i);
        deque.AddLast(i);
    }

    for(int i: deque)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 1; i <= 3; i++)
    {
        cout << deque.RemoveLast() << " ";
    }
    cout << endl;

    for (int i = 1; i <= 3; i++)
    {
        cout << deque.RemoveFirst() << " ";
    }
    cout << endl;

    for(int i: deque)
    {
        cout << i << " ";
    }
    cout << endl;
}
