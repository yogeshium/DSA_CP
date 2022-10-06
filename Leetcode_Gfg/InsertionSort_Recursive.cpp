#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int A[], int n, int i=1)
{
    if(i==n || n==1 || n==0)
        return ;


    int elmnt = A[i];
    int j=i-1;
    for(;j>=0;j--)
    {
        if(A[j]>elmnt)
            A[j+1]=A[j];
        else
            break;
    }
    A[j+1]=elmnt;


    InsertionSort(A,n,i+1);
}

int main()
{

    int arr[]={10,20,5,7,19,18,17,1,3,2,5,7,0,9,8,2,33,23,55,22};
    InsertionSort(arr,20);
    cout<<"\n";
    for(int i=0;i<20;i++)
        cout<<arr[i]<<" ";
    return 0;
}
