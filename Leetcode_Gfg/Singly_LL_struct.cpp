#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void insertAtLast(int d, ListNode* temp)
    {
        ListNode* naya = new ListNode(d);
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next = naya;
    }


void print(ListNode* temp)
    {
        cout<<endl;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }








//Reverse Linked List - Approach 1
  ListNode* reverseList(ListNode* head)
    {
        ListNode* prev, *curr, *temp;
        prev = nullptr;
        temp = head;
        curr = temp;
        while(temp!=nullptr)
        {
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;

        }
        return prev;
    }


    //Reverse Linked List - using Recursion -  Approach 2
    /*
    ListNode* Reverse(ListNode* temp, ListNode* curr, ListNode* prev)
    {
        if(temp==NULL)
        {
            return prev;
        }
        temp = temp->next;
        curr->next = prev;
       return Reverse(temp, temp, curr);
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        return Reverse(head,head,prev);
    }
    */

    //Reverse Linked List - Approach 3
    /*
     ListNode* reverseList(ListNode* head)
    {
       if(head == NULL || head->next ==NULL)
            return head;

        ListNode* chotaHead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return chotaHead;
    }

    */


//Middle of Linked List
    //Approach 1 - find length of linked list
    /*
        ListNode* middleNode(ListNode* head)
    {
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {   cnt++;
            temp=temp->next;
        }
        int mid = cnt/2 + 1;
        temp = head;
        for(int i=1;i<mid;i++)
        {
            temp = temp->next;
        }
        return temp;
    }
    */


    //Approach 2 - Pro banda and Noob banda (More Optimized)
    /*
        Pro banda 2 step leta hai lekin Noob banda 1 step hi leta hai ek baar mai
    */
    /*
    ListNode* middleNode(ListNode* head)
    {
        ListNode* pro = head; ListNode *noob = head;
        while(pro!=NULL )
        {
           if(pro->next !=NULL)
           {
                pro= pro->next->next;
                noob = noob->next;
           }
           else
            break;
        }
        return noob;
    }
    */



int main()
{
    ListNode* head = new ListNode(1);
    insertAtLast(2,head);
    insertAtLast(3,head);
    insertAtLast(4,head);
    insertAtLast(5,head);
    print(head);

    head = reverseList(head);

    print(head);
}
