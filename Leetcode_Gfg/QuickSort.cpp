#include<bits/stdc++.h>
using namespace std;

int Partition(int A[], int s, int e)
{


    //Take Pivot
    int pivot = A[s];

    //Pivot se chote kon kon hai count kro taki Right Place mile
    int cnt = 0;
    for(int i=s+1;i<=e;i++)
        if(A[i]<=pivot)
            cnt++;

    int RightPlace=s+cnt;//Right Place mil gya

    //Swap krdo Right Place se
    int temp = A[RightPlace];
    A[RightPlace]=A[s];
    A[s]=temp;

    //Ab 3rd part
    int i=s, j=e;
    while(i<RightPlace && j>RightPlace)
    {
        while(A[i]<=pivot)
            i++;
        while(A[j]>pivot)
            j--;
        while(i<RightPlace && j>RightPlace)
            {
                int temp = A[i];
                A[i]=A[j];
                A[j]=temp;
                i++;j--;
            }
    }

   return RightPlace;
}

void quickSort(int A[], int s, int e)
{
    //Base Case
    if(s>=e)
        return ;

    //Partition
    int p=Partition(A, s, e);

    //Recursive Call
    quickSort(A,s,p-1);
    quickSort(A,p+1,e);
}



int main()
{
    int A[]={10,9,7,8,2,1,3,5,4,6};
    cout<<"\nBefore Sorting \n";
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
    quickSort(A,0,9);
    cout<<"\nAfter Sorting \n";
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
}
