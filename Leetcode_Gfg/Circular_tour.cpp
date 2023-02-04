//Circular tour

#include<bits/stdio.h>
using namespace std;


//Approach 1 :
int tour(petrolPump p[],int n)
    {
       int front = 0, rear=0,i=1, balance = 0;
       bool flag = true;

       while(i<=2*n)
       {
            flag=true;
            balance += p[rear].petrol-p[rear].distance;

            if(balance<0)
            {
                front = rear+1;
                flag=false;
                balance =0;
            }
            rear= (rear+1)%n;

            if(rear==front && flag)
                return front;
            i++;
       }
       return -1;
    }

//Approach 2 :

int tour(petrolPump p[],int n)
    {
       int front = 0, r=0, balance = 0 , deficit=0;

       for(;r<n;r++)
       {
           balance += p[r].petrol-p[r].distance;
           if(balance<0)
           {
               deficit+=balance;
               front = r+1;
               balance=0;
           }
       }
       if(deficit+balance>=0)
            return front;
        return -1;
    }







int main()
{

}
