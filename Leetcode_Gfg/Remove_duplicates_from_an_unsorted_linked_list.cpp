//Remove duplicates from an unsorted linked list
/*
Given an unsorted linked list of N nodes. The task
is to remove duplicate elements from this unsorted
Linked List. When a value appears in multiple nodes,
the node which appeared first should be kept, all
others duplicates are to be removed.
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
void insertAtLast(int d, Node* temp)
    {
        Node* naya = new Node(d);
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next = naya;
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



//Approach 1 : 2 Loop
    /*
        Har node ka uske aage walon mai check karenge
        ki kya ye hai inme , agr haa to delete agr nahi
        to aage badh jao. Last tk check karenge.
        Like 0th ka 1 se leke n-1 tak check karenge
        1st ka 2nd se leke n-1 tak ...
        Aese chalenge
        O(n^2)
    */
     Node * removeDuplicates( Node *head)
    {
        Node* temp=NULL,*prev= NULL, *curr=head;
        while(curr->next !=NULL)
        {
            temp = curr->next;
            prev = curr;
            while(temp)
            {
                if(temp->data == curr->data)
                {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
            curr= curr->next;
            if(!curr)
                break;
        }
        return head;
    }


//Approach 2 : Sort krdo pehle LL ko, then "Remove Element in Sorted order" lga do
    /*
        (ye jab merge sort seekhenge tab lagayenge
    */



//Approach 3 : Use Hash Map

    /*
     Node * removeDuplicates( Node *head)
    {
        Node* temp = head, *prev = head;
        unordered_map<int,bool> mp;
        while(temp)
        {
            if(mp.find(temp->data)!=mp.end())
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                mp[temp->data]=true;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
    */




int main()
{
    Node* head = new Node(1);
    insertAtLast(2,head);
    insertAtLast(2,head);
    insertAtLast(3,head);
    insertAtLast(3,head);
    print(head);
    return 0;
}
