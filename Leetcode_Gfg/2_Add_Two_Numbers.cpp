//2. Add Two Numbers


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




// My Approach 1 -> Using new external list;
  /*  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int sum, carry= 0;
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        while(l1 && l2)
        {
            ListNode* temp = new ListNode();
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            temp->val = sum%10;
            if(curr->val != -1)
            {
                curr->next = temp;
                curr = temp;
            }
            else
            {
                ans->val = temp->val;
            }
            l1= l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            ListNode* temp = new ListNode();
            sum = l1->val + carry;
            carry = sum/10;
            temp->val = sum%10;
            if(curr->val != -1)
            {
                curr->next = temp;
                curr = temp;
            }
            else
            {
                ans->val = temp->val;
            }
            l1= l1->next;
        }
        while(l2)
        {
            ListNode* temp = new ListNode();
            sum = l2->val + carry;
            carry = sum/10;
            temp->val = sum%10;
            if(curr->val != -1)
            {
                curr->next = temp;
                curr = temp;
            }
            else
            {
                ans->val = temp->val;
            }
            l2= l2->next;
        }
        if(carry != 0)
        {
            ListNode* temp = new ListNode();
            temp->val = carry;
            if(curr->val != -1)
            {
                curr->next = temp;
                curr = temp;
            }
            else
            {
                ans->val = temp->val;
            }
        }
        return ans;
    }
*/
