//82. Remove Duplicates from Sorted List II
/*
Given the head of a sorted linked list,
 delete all nodes that have duplicate numbers,
 leaving only distinct numbers from the original list.
 Return the linked list sorted as well.
*/
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


//Approach : samjhna hai to ek baar dry run kr lena

ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode dummy(0,head);
        ListNode *prev = &dummy, *curr=head;
        while(curr)
        {
            ListNode* nxt = curr->next;
            while(nxt && curr->val == nxt->val)
            {
                ListNode* temp = nxt->next;
                delete nxt;
                nxt=temp;
            }
            if(curr->next == nxt)
            {
                prev = curr;
            }
            else
            {
                prev->next = nxt;
                delete curr;
            }
            curr = nxt;
        }
        return dummy.next;
    }

//Recursive Approach
    // Iss code ki beauty tab pta chalegi jab tu dry run karega

 ListNode* deleteDuplicates(ListNode* head) {
		// if list contains no node
        if(!head)
            return 0;
		//if list containg a single node return head
        if(!head -> next)
            return head;

		// keepitn val of head in a temp variable var.
        int val = head ->val;
		// temp contain the reference of next  node
        ListNode *temp = head -> next;

		// if the next node have different value then,
		// update head->next by temp(temp contains reference to next node)
        if(temp -> val != val)
        {
            head -> next = deleteDuplicates(temp);
            return head;
        }
        else
        {
			// if the values are same just update temp to temp->next;
           while(temp && temp -> val == val)
            {
				// assigning temp to p
                ListNode *p = temp;
				// updating temp with next node
                temp = temp->next;
				// freeing the memory
                delete p;
            }
            return deleteDuplicates(temp);
        }
    }





int main()
{
    ListNode* head = new ListNode(1);
    insertAtLast(2,head);
    insertAtLast(2,head);
    insertAtLast(3,head);
    insertAtLast(3,head);
    print(head);
    return 0;
}
