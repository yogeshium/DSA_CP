//138. Copy List with Random Pointer
//Read the Question first


#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


//My Approach :  Approach 1 : (Love Babbar)  T.c. = 0(n^2)
/*
// cloning list using next pointer
int distance(Node* x, Node* y)
    {
        if(y==NULL)
            return -1;
        int cnt=0;
        while(x!=y)
        {
            cnt++;
            x=x->next;
        }
        return cnt;
    }

    Node* returnAdr(Node* x, int n)
    {
        if(n==-1)  return NULL;
        while(n>0)
        {    x=x->next;
            n--;
        }
       // cout<<x->data;
        return x;
    }

    Node* copyRandomList(Node* head)
    {
        if (head==NULL)
            return head;
        vector<int> adr;
        Node *ans = new Node(head->data);
        Node* curr= ans;
        adr.push_back(distance(head,head->arb));

        Node* temp = head->next;
        while(temp)
        {
            Node* naya = new Node(temp->data);
            curr->next = naya;
            curr = naya;
            adr.push_back(distance(head,temp->arb));
           temp= temp->next;
        }


        temp = ans;int i=0;
        while(temp)
        {
            temp->arb = returnAdr(ans,adr[i]);
            i++;
            temp=temp->next;
        }
        return ans;
    }
*/


//Approach 2 : (using hash map) ( o(n)) ( babbar)
/*
Node* copyRandomList(Node* head)
    {
        if(head==NULL)
            return head;
        unordered_map<Node*, Node*> oldnew;

        Node* clone = new Node(head->val);

        oldnew[head]=clone;
        Node* curr= clone;
        Node* temp = head->next;
        while(temp)
        {
            Node* naya = new Node(temp->val);
            oldnew[temp]=naya;
            curr->next = naya;
            curr= naya;
            temp = temp->next;
        }
        temp= head; curr= clone;
        while(temp)
        {
            curr->random = oldnew[temp->random];
            temp= temp->next;
            curr= curr->next;
        }
    return clone;
    }
*/

//Approach 3
/*
Node* copyRandomList(Node* head)
    {
        if(head==NULL)
            return head;

        //step 1 :

        Node* clone = new Node(head->val);
        Node* curr= clone;
        Node* temp = head->next;
        while(temp)
        {
            Node* naya = new Node(temp->val);
            curr->next = naya;
            curr= naya;
            temp = temp->next;
        }

        //Step 2 :

        Node* t1=head , *t2 = head, *c1=clone, *c2 = clone;
        while(t2 && c2)
        {
            t2=t2->next;
            c2=c2->next;
            t1->next = c1;
            t1=t2;

            c1->next = t1;
            c1=c2;
        }

        //step 3 :

        temp=head;
        while(temp)
        {
            if(temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp=temp->next->next;
        }

        //step 4 :

        t1=head,c1=clone;
        while(t1 && c1)
        {
            t1->next = c1->next;
            t1= c1->next;
            if(!t1)
                break;
            c1->next = t1->next;
            c1 = t1->next;
        }

        return clone;
    }
*/
