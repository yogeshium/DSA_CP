#include <bits/stdc++.h>
using namespace std;


void printQ(deque<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop_front();
    }
}

int Sum(vector<int> A, int k)
{
    int sum=0;
    deque<int> minQ;
    deque<int> maxQ;

    int i=0, j=0;
    while(j<A.size())
    {

        //maxQ and minQ mai element daalo
        if(maxQ.empty())
            maxQ.push_back(j);
        else
        {
            if(A[j]<A[maxQ.front()])
                maxQ.push_back(j);
            else
                maxQ.push_front(j);
        }

        if(minQ.empty())
            minQ.push_back(j);
        else
        {
            if(A[j]<A[minQ.front()])
                minQ.push_front(j);
            else
                minQ.push_back(j);
        }

        //Check for is it in first window
        if(j-i<k)
        {
            //check is it in last index of first window
            if(j==k-1)
                sum = sum+A[minQ.front()] + A[maxQ.front()];
            j++;
        }
        else
        {
            while(j-minQ.front()>=k)
                minQ.pop_front();
            while(j-maxQ.front()>=k)
                maxQ.pop_front();
            sum = sum+A[minQ.front()]+A[maxQ.front()];
            i++;j++;
        }

    }
    return sum;
}

int main()
{

    vector<int>v = {2,5,-1,7,-3,-1,-2};
    cout<<"\nAns= "<<Sum(v,4);
}
