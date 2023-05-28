#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // TODO:- write a destructor to delete the Node
    ~Node()
    {
        // write your code here
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

Node *reverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return NULL;
    }

    int len = getLength(head);
    if (k > len)
    {
        // cout << "Enter valid value for k "<< endl;
        return head;
    }

    // it means number of nodes in LL is >=k
    // Step A: reverse first k nodes of LL
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step2: recursive call
    if (forward != NULL)
    {
        // we still have nodes to reverse
        Node *recursionAns = reverseKNodes(forward, k);
        head->next = recursionAns;
    }

    // Step3 : return head of the modified LL
    return prev;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);
    head = reverseKNodes(head, 3);
    cout << endl;
    print(head);

    return 0;
}
