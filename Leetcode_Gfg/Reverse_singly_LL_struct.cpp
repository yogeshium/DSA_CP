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









//Reverse Linked List
    //Approach 1
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


    //Approach 2 : using Recursion

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

    //Approach 3 : (best aproach)

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




//92. Reverse Linked List II : reverse the nodes of the list from position left to position right, and return the reversed list

    //Approach 1 (My approach) :

    /*
    ListNode* reverseList(ListNode* temp, ListNode* term)
    {
        if(temp==term || temp->next == term)
             return temp;
        ListNode* chotaHead = reverseList(temp->next, term);

        temp->next->next = temp;
        temp->next = term;

        return chotaHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(left==right)
        { return head;}
        else
        {
            ListNode* leftMost = head, *rightMost = head;

            for(int i=1;i<=right;i++)
                rightMost = rightMost->next;

            if(left == 1)
            {    return reverseList(head,rightMost);}
            else
            {
                for(int i=1;i<left-1;i++)
                leftMost = leftMost->next;
                leftMost->next = reverseList(leftMost->next,rightMost);
            }

            return head;
        }

    }
    */



//25. Reverse Nodes in k-Group
    //Approach 1 : (my approach)
    /*
        ListNode* reverseList(ListNode* temp, ListNode* term)
    {
        if(temp==term || temp->next == term)
             return temp;
        ListNode* chotaHead = reverseList(temp->next, term);

        temp->next->next = temp;
        temp->next = term;

        return chotaHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(k==1)
        {
            return head;
        }
        else
        {
            int n = 0;
            ListNode* temp, *pl,*lm,*rm;
            temp = head;
            while(temp!=NULL)
            {
                n++;
                temp = temp->next;
            }
            n= n/k;lm=head;pl=head;rm=head;
            while(n--)
            {
                pl = rm;
                for(int i=1;i<=k;i++)
                    rm=rm->next;
                if(lm==head)
                {
                    head = reverseList(head,rm);
                }
                else
                {
                    lm->next = reverseList(lm->next,rm);
                }
                lm=pl;
            }
            return head;
        }
    }
    */

    //Approach 2 : (Babbar Approach)
    /*  Recursive :
        "Ek Case Solve Krlo Baaki Recursion Samahal Lega " = Ek group reverse krdo ,
        baki recursion kr lega"
    */
    /*
        ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++)
        {
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; i++)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
    */
    /* Iterative :
        ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while(true){
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for(int i = 0; i < k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
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
    pSrint(head);

    head = reverseList(head);

    print(head);
}
