//Reverse a Linked List in groups of given size
#include<bits/stdc++.h>
using namespace std;


struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void insertAtLast(int d, Node* &head)
    {
        Node* naya = new Node(d);
        if(head==NULL)
            head = naya;
        else
        {
            Node* temp = head;
            while(temp->next !=NULL)
                temp=temp->next;
            temp->next = naya;
        }
    }


void print(Node* temp)
    {
        cout<<endl;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }


//                                              Solution:

struct Node* reverseList(struct Node* lm , struct Node* rm, struct Node* val)
    {
        if(lm==rm)
            return lm;
        struct Node* chotaHead = reverseList(lm->next,rm,val);

        lm->next->next = lm;
        lm->next = val;
        return chotaHead;
    }

    struct Node *reverse (struct Node *head, int k)
    {
        if(head==NULL)
            return NULL;

        struct Node* lm= head, *rm=head;
        int i=0;
        while(i<k-1 && rm->next!=NULL)
        {
            rm = rm->next;
            i++;
        }
        struct Node* val=reverse(rm->next,k);
        return reverseList(lm,rm,val);
    }


int main()
{
    struct Node* head = NULL;
    insertAtLast(1,head);
    insertAtLast(2,head);
    insertAtLast(3,head);
    insertAtLast(4,head);
    insertAtLast(5,head);
    insertAtLast(6,head);
    insertAtLast(7,head);
    insertAtLast(8,head);
    print(head);

    head = reverse(head,4);
    print(head);
}
