//Merge K sorted linked lists

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};


//My Approach : (using  merge 2 linked list)
/*
    Node* merge2LL(Node* list1, Node* list2)
    {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;

        if(list2->data<list1->data)
        {
            Node* temp = list1;
            list1=list2;
            list2=temp;
        }

         Node* c1 = list1, *c2 = list2;

        while(c1->next && c2)
        {
            if(c1->data<=c2->data && c1->next->data>c2->data)
            {
                Node* temp = c2;
                c2=c2->next;

                temp->next = c1->next;
                c1->next = temp;
            }
            else
            {
                c1=c1->next;
            }
        }

        if(c2)
        {
            c1->next = c2;
        }

        return list1;

    }
    Node * mergeKLists(Node *arr[], int k, int i=0)
    {
        if(i>=k-1)
            return arr[i];

        Node* list1 = arr[i];
        Node* list2 = mergeKLists(arr,k,i+1);

        return merge2LL(list1, list2);
    }

*/


//Approach 2 :
