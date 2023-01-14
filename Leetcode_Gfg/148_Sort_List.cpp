//148. Sort List
//Given the head of a linked list, return the list after sorting it in ascending order.

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



//Merge 2 sorted linked list

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






    ListNode* mergeSort(ListNode* head)
    {
        if(head==NULL)
            return head;
        if(head->next ==NULL)
            return head;

        ListNode *t1=head, * t2, *fp, *sp;
        sp = head;fp=head;
        while(fp)
        {
            if(fp->next ==NULL)
                break;
            if(fp->next->next == NULL)
                break;
            sp=sp->next;
            fp = fp->next->next;
        }
        t2= sp->next;
        sp->next = NULL;

        cout<<"\n t1 = ";print(t1);
        cout<<"\n t2 = ";print(t2);

        t1= mergeSort(t1);
        t2 = mergeSort(t2);

        return merge(t1,t2);
    }

    ListNode* sortList(ListNode* head)
    {
        head = mergeSort(head);
        return head;
    }






    int main()
    {
        ListNode *head = new ListNode(4);
        ListNode *curr= head;
        insertAtLast(3,curr);
        insertAtLast(2,curr);
        insertAtLast(1,curr);
        print(head);
        cout<<"\nAfter Sort";
        head = mergeSort(head);
        print(head);
    }
