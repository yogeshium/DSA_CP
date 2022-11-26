#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
       this->data = data;
       next=NULL;
       prev=NULL;
    }
};

void print(Node* temp)
{
       cout<<"\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }

}

void insertAtPos(Node* &head, int pos, int d)
{
    Node* naya=new Node(d);
    if(pos<=1)
    {
        if(head==NULL)
        {
            head = naya;
        }
        else
        {
            naya->next = head;
            head->prev=naya;
            head = head->prev;
        }
    }
    else
    {
        Node* temp = head;
        int cnt =1;
        while(cnt<pos-1  && temp->next !=NULL)
         {
             cnt++;
             temp = temp->next;
         }
         if(temp->next != NULL)
         {
             // Insert at middle
            naya->next = temp->next;
            temp->next->prev = naya;
            naya->prev = temp;
            temp->next= naya;
         }
         else
         {
             //Insert at end
            temp -> next = naya;
            naya ->prev = temp;
         }

    }
}

void deleteAtPos(Node* &head, int pos)
{
    if(head == NULL || pos<1)
        return ;
    Node* temp=head;
    if(pos==1)
    {
        head = head->next;
        free(temp);
    }
    else
    {
        int cnt = 1;
        while(cnt<pos && temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        if(temp==NULL)
            return ;
        if(temp->next!= NULL)
        { //At Middle
           temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = NULL;
            temp->prev = NULL;
            free(temp);
        }
        else
        {
            //At End
            temp->prev->next = NULL;
            temp->prev = NULL;
            temp->next = NULL;
            free(temp);
        }

    }
}

int main()
{
    Node* head = new Node(10);
    insertAtPos(head,2,11);
    insertAtPos(head,2,12);
    insertAtPos(head,4,13);
    print(head);
    deleteAtPos(head,1);
    print(head);
    deleteAtPos(head,2);
    print(head);
    deleteAtPos(head,2);
    print(head);
    deleteAtPos(head,1);
    print(head);
}
