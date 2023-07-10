#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max-heap
    priority_queue<int> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Size: " << pq.size() << endl;
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    cout << "Top element : " << pq.top() << endl;
    pq.pop();
    if (pq.empty())
    {
        cout << "Heap is empty " << endl;
    }
    else
    {
        cout << "Heap is not empty " << endl;
    }

    return 0;
}
