//Given a linked list of 0s, 1s and 2s, sort it.
/*
Given a linked list of N nodes where nodes can
contain values 0s, 1s, and 2s only. The task is to
segregate 0s, 1s, and 2s linked list such that all
zeros segregate to head side, 2s at the end of the
linked list, and 1s in the mid of 0s and 2s.
*/

#include<bits/stdc++.h>
using namespace std;


 Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


void insertAtLast(int d, Node* temp)
    {
        Node* naya = new Node(d);
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next = naya;
    }


void print(Node* temp)
    {
        cout<<endl;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }






//Approach 1 : using Sort012 (jo humne array pe kiya tha).
    /*
    hum sbse pehle saare elements LL se ek array mai daal lenge
    then uspe Sort012 lga denge .
    Then sorted array lo LL mai wapis daal denge;
    */

    /*
     void sort012(vector<int>& A)
    {
        int zr=0, on=0 , tw=A.size()-1;
        while(zr<=tw)
        {
            if(A[zr]==0)
            {
                //swap zr and on
                int temp = A[on];
                A[on]=A[zr];
                A[zr]=temp;
                zr++;on++;
            }
            else if(A[zr]==1)
            {
                zr++;
            }
            else if(A[zr]==2)
            {
                //swap zr and tw
                int temp = A[zr];
                A[zr]=A[tw];
                A[tw]=temp;
                tw--;
            }
        }
    }
    Node* segregate(Node *head)
    {
        vector<int> v;
        Node* temp = head;
        while(temp)
        {
            v.push_back(temp->data);
            temp= temp->next;
        }
        sort012(v);
        temp = head;int i=0;
        while(temp)
        {
            temp->data = v[i++];
            temp = temp->next;
        }

        return head;
    }
    */

//Approach 2: (babbar)
    /*
    Hum ek kaam krte hai: Count kr lete hai kitne
    Zeroes hai, Ones hai and Two hai.
    Fir LL pe travese krte huye Zero , One and Two ko
    daal denge.
    */

    /*
    Node* segregate(Node *head)
    {

        int zero=0,one =0, two = 0;
        Node *temp = head;
        while(temp)
        {
            if(temp->data == 0)
                zero++;
            else if(temp->data == 1)
                one++;
            else
                two++;
            temp = temp->next;
        }
        temp = head;
        while(zero-- && temp)
        {
            temp->data= 0;
            temp = temp->next;
        }
        while(one-- && temp)
        {
            temp->data = 1;
            temp = temp->next;
        }
        while(two-- && temp)
        {
            temp ->data =2;
            temp = temp->next;
        }

        return head;
    }
    */

//Approach 3 :  (Interviewer : "Data Replacement is not allowed")
    /*
    Interviewer ne keh diya ki data replacement is not allowed.
    To kya bacha humare pass replace krne ko : LINKS;
    Do hi chiz to hoti hai LL ke andar : ek data and dusra pointer.
    To pointer pe changes krne hai .

    To kyu na aesa krte hai ki ek Zero ka , ek One ka and ek Two ka
    linked list bana lete hai and saare 0, 1 & 2 jo given LL mai honge
    vo corresponding Zero , One, Two LL mai daal denge.
    Last mai Merge kr lenge.
    */

    //My code :
    /*
    //zh - Zero Head, zt - Zero Tail.
    //Same for baaki ke liye
    Node* segregate(Node *head)
    {
        Node *temp = head;
        Node *zh=NULL, *zt=NULL, *ot=NULL,*oh=NULL,*th=NULL,*tt=NULL;

        while(temp)
        {
            if(temp->data== 0)
            {
                if(zh)
                {
                    zt ->next = temp;
                    zt=temp;
                    temp = temp->next;
                    zt->next = NULL;
                }
                else
                {
                    zh = temp;
                    zt=temp;
                    temp = temp->next;
                    zt->next= NULL;
                }
            }
            else if(temp->data == 1)
            {
                if(oh)
                {
                    ot ->next = temp;
                    ot=temp;
                    temp = temp->next;
                    ot->next = NULL;
                }
                else
                {
                    oh = temp;
                    ot=temp;
                    temp = temp->next;
                    ot->next= NULL;
                }
            }
            else
            {
                if(th)
                {
                    tt ->next = temp;
                    tt=temp;
                    temp = temp->next;
                    tt->next = NULL;
                }
                else
                {
                    th = temp;
                    tt=temp;
                    temp = temp->next;
                    tt->next= NULL;
                }
            }
        }
        //Merge
        if(zh && oh && th)
        {
            zt->next= oh;
            ot->next = th;
            head = zh;
        }
        else if(zh && oh)
        {
            zt->next = oh;
            head = zh;
        }
        else if(zh && th)
        {
            zt->next = th;
            head = zh;
        }
        else if(oh && th)
        {
            ot->next = th;
            head = oh;
        }
        else if(zh)
        {
            head = zh;
        }
        else if(oh)
        {
            head = oh;
        }
        else if(th)
        {
            head = th;
        }
        return head;
    }
    */

    //Babbar Code :




int main()
{


return 0;
}
