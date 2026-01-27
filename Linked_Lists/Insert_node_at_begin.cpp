#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;

    Node(int val,Node* ptr)
    {
        data = val;
        next = ptr;
    }

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node* insertAtBeg(Node* head,int val)
{
    Node* temp = new Node(val,head);
    return temp;
}

void printLL(Node* head)
{
    Node* ptr = head;
    while(ptr->next!=nullptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<ptr->data<<endl;
}

int main()
{
    vector<int> v = {1,2,3,4};
    
    Node* head = new Node(v[0]);
    head->next = new Node(v[1]);
    head->next->next = new Node(v[2]);
    head->next->next->next = new Node(v[3]);


    // head = insertAtBeg(head,5);

    // printLL(head);
    
}