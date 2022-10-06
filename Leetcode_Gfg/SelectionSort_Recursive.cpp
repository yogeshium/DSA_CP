#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[],int n,int i=0)
{
    //Base Case
    if(i>=n-2 || n==1 || n==0)
        return ;

    //1 case solveed
        int m=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[m])
                m=j;
        //Swap
        int temp = arr[i];
        arr[i]=arr[m];
        arr[m]=temp;
    SelectionSort(arr,n,i+1);
}

int main()
{

    int arr[]={10,20,5,7,19,18,17,1,3,2,5,7,0,9,8,2,33,23,55,22};
    SelectionSort(arr,20);
    cout<<"\n";
    for(int i=0;i<20;i++)
        cout<<arr[i]<<" ";
    return 0;
}
