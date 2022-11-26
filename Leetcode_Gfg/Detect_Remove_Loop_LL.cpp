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


//141. Linked List Cycle
    //Approach 1:
    /*
    bool hasCycle(ListNode *head)
    {
       if(head == NULL)
            return false;
        map<ListNode* , bool> mp;
        while(head!=NULL)
        {
            if(mp.find(head)!=mp.end())
               { return true;}
            else
            {
                mp[head]=true;
            }
            head = head->next;
        }
        return false;
    }
    */
    //Approach 2 : (Floyd's Cycle detection Algo)
     bool hasCycle(ListNode *head)
    {
        if(head == NULL)
            return false;

        ListNode* fp = head, *sp = head;
        while(fp != NULL)
        {
            if(fp->next==NULL)
                return false;
            fp=fp->next->next;
            sp=sp->next;

            if(fp==sp)
                return true;
        }
        return false;
    }

//142. Linked List Cycle II -  return the node where the cycle begins. If there is no cycle, return null
    //Approach 1 : Using map
    ListNode *detectCycle(ListNode *head)
    {
       if(head == NULL)
            return NULL;
        map<ListNode* , bool> mp;
        while(head!=NULL)
        {
            if(mp.find(head)!=mp.end())
               { return head;}
            else
            {
                mp[head]=true;
            }
            head = head->next;
        }
        return NULL;
    }

    //Approach 2 : Floyd' Cycle Finding Algorithm
    /* How its working : gfg article "Floyd's Cycle Finding Algorithm"
    /*
    ListNode *detectCycle(ListNode *head)
    {
        if(head == NULL)
            return NULL;
       ListNode* fp= head, *sp = head;

       while(fp!=NULL)
       {
           if(fp->next == NULL)
             return NULL;
           fp = fp->next->next;
           sp = sp->next;
           if(fp==sp)
           {
               break;
           }
       }
       if(fp!=NULL)
       {
           sp = head;
           while(fp != sp)
           {
               fp = fp->next;
               sp = sp->next;
           }
           return fp;
       }
       return NULL;
    }
    */
//Remove loop in Linked List (GFG)
    //Approach :
    /*
        void removeLoop(ListNode* head)
        {
            ListNode* start = StartingNode(head);//Return the Node where cycle begins

            if(start != NULL)
            {
                 ListNode* temp = start;

                while(temp->next !=start)
                    temp = temp->next;

                temp->next = NULL;
            }

        }
    */





int main()
{
    ListNode* head = new ListNode(1);
    insertAtLast(2,head);
    insertAtLast(3,head);
    insertAtLast(4,head);
    insertAtLast(5,head);
    insertAtLast(6,head);
    print(head);

    head = reverseBetween(head,2,5);

    print(head);
}
