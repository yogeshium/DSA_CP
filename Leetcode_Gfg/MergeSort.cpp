#include<bits/stdc++.h>
using namespace std;


//Using Gap Method - Merge Two Sorted Array
void merge(int A[], int s, int m, int e)
    {
         int n1=m-s+1, n2=e-m;
         int g=n1+n2;
         g=(g/2) + (g%2);
         for(;g>0;g=(g/2) + (g%2))
         {
             int i=s;int j=s+g;
             while(j<=e)
             {
                 if(A[i]>A[j])
                 {
                    //swap
                    int temp = A[i];
                    A[i]=A[j];
                    A[j]=temp;
                 }
                 i++;j++;
             }
              if(g==1)
                break;
         }
    }

void mergeSort(int A[], int s, int e)
    {
        if(s>=e)
          return ;
        int m= s+((e-s)>>1);
        mergeSort(A,s,m);
        mergeSort(A,m+1,e);
        merge(A,s,m,e);
    }


int main()
{
    int A[] = {6334,4098,7968,4523,277,6956,4560,2062,5705,5743,879,5626,9961,491,2995,741,4827};
    cout<<"\nBefore Sorting :\n";
    for(int i=0;i<17;i++)
        cout<<A[i]<<" ";
    mergeSort(A,0,16);

    cout<<"\nAfter Sorting \n";
    for(int i=0;i<17;i++)
        cout<<A[i]<<" ";

}
