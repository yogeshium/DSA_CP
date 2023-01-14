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




    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;

        ListNode* c1 = list1, *c2=list2, *temp = NULL;

        while(c2->val < c1->val)
        {list1 = list2;temp = c2;c2=c2->next;if(c2==NULL) break;}

        if(c2!=list2)
        {
            temp->next = c1;
        }
        if(c2==NULL)
            return list1;
        while(c1->next && c2)
        {
            if(c2->val >= c1->val && c2->val <= c1->next->val)
            {
                temp = c2;
                c2 = c2->next;
                temp->next=c1->next;
                c1->next = temp;
                c1= temp;
            }
            else
            {c1= c1->next;}
        }

        if(c2)
        {
            c1->next = c2;
        }
        return list1;
    }


int main()
{


    return 0;
}
