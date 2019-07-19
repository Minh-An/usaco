#include "randomized_queue.h"

int main(int argc, char const *argv[])
{
    RandomizedQueue<int> queue = RandomizedQueue<int>();
    for (int i = 1; i <= 10; i++)
    {
        queue.Enqueue(i);
    }

    for(int i: queue)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << queue.Sample() << " ";
    }
    cout << endl;

    for(int i: queue)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << queue.Dequeue() << " ";
    }
    cout << endl;

    for(int i: queue)
    {
        cout << i << " ";
    }
    cout << endl;
}
