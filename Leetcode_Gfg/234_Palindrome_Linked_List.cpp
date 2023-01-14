//234. Palindrome Linked List
//Check if Linked List is Palindrome

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




//My Approach
    /*
    copy mai dekh lena
    */
    int count(ListNode* temp)
    {
        int cnt = 0;
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    bool isPalindrome(ListNode* head)
    {
        int n=count(head);
        if(n==1)
            return true;
        int t=n/2;
        ListNode* prev=NULL,*curr=head,*nxt=head;
        while(t--)
        {
            curr=nxt;
            nxt=nxt->next;
            curr->next = prev;
            prev = curr;
        }
        ListNode* i=curr,*j=NULL;
        if(n&1)
            j=nxt->next;
        else
            j=nxt;

        while(i && j)
        {
            if(i->val!=j->val)
                return false;
            i=i->next;
            j=j->next;
        }
        return true;
    }

//Approach 1 : (babbar)
    /*
    LL ke sare element ko array mai daal do.
    Then array mai palindrome wala laga do (two pointer).
    */

//Appraoch 2 : (babbar)
    /*
    = Same my approach
    middle tak pohonch jao and aage ko reverse krdo. then dono
    part ko compare krlo.
    */
    //Code (gfg)
    /*
    int Count(Node* temp)
    {
        int cnt;
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int n= Count(head);
        if(n==1)
            return true;

        int A[n];
        int j=0;
        Node* temp= head;
        while(temp)
        {
            A[j++] = temp->data;
            temp = temp->next;
        }

        int i=0;j--;
        while(i<j)
        {
            if(A[i]!=A[j])
                return false;
            i++;j--;
        }
        return true;
    }
    */



    int main()
    {


        return 0;
    }
