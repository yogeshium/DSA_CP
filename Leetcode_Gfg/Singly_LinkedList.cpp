#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int n)
    {
        this->data=n;
        this->next = NULL;
    }
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};
    void print(Node* &head)
    {
        Node* temp = head;
        cout<<"\n";
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
    }


void insertPos(Node* &head, int d, int pos)
{
    Node* naya = new Node(d);
    if(pos==1)
    {
        naya->next = head;
        head=naya;
    }
    else
    {
        Node* temp = head;
        int i=1;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        naya->next = temp->next;
        temp->next = naya;
    }
}
deletePos(Node* &head , int pos)
{
    if(pos==1)
    {
        Node* temp = head;
        head=head->next;
       free(temp);
    }
    else
    {
        Node* curr = head;Node* prev=NULL;
        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next = NULL;
        free(curr);
    }
}

int main()
{
    Node node1(1);
    Node* head = &node1;
    insertPos(head,10,1);
    insertPos(head,11,3);insertPos(head,11,3);insertPos(head,11,3);insertPos(head,11,3);insertPos(head,11,3);
    print(head);

     deletePos(head, 1);
    print(head);
    return 0;
}
