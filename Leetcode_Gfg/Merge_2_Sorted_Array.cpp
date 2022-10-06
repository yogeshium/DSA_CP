#include<bits/stdc++.h>
using namespace std;
/*
//With Using Extra Space
void Merge(int *N1, int *N2, int n1, int n2)
{
    int i=0, j=0;
    int A[n1+n2]={0};
    int c=0;
    while(i<n1 && j<n2)
    {
        if(N1[i]<N2[j])
            A[c++]=N1[i++];
        else if (N1[i]==N2[j])
        {
            A[c++]=N1[i++];
            A[c++]=N2[j++];
        }
        else
            A[c++]=N2[j++];
    }
    while(i<n1)
        A[c++]=N1[i++];
    while(j<n2)
        A[c++]=N2[j++];

    for(i=0;i<n1;i++)
        N1[i]=A[i];
    for(int j=0;j<n2;j++,i++)
        N2[j]=A[i];
}
*/

//Without Using Extra Space -> 1. Using Selection Sort
/*
void SelectionSort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
          {
              if(A[m]>A[j])
                m=j;
          }
        int temp = A[i];
        A[i]=A[m];
        A[m]=temp;
    }
}

void Merge(int* N1, int *N2, int n1, int n2)
{
        int i=0;
        while(i<n1)
        {
            if(N1[i]>N2[0])
            {
                //Swap
                int temp = N1[i];
                N1[i]=N2[0];
                N2[0]=temp;
                SelectionSort(N2,n2);
            }
            else if(N1[i]==N2[0])
                i++;
            else
                i++;
        }

}*/


//Merge Without Extra Space -> 2. Using GAP Method

void Merge(int* N1, int* N2, int n1, int n2)
{
    int g=n1+n2;
    g=(g/2) + (g%2);
    for(;g>0;g=(g/2) + (g%2))
    {
        //Print
        cout<<"\n G = "<<g;
        cout<<"\nN1 = ";
        for(int i=0;i<n1;i++)
            cout<<N1[i]<<" ";
        cout<<"\nN2 = ";
        for(int i=0;i<n2;i++)
            cout<<N2[i]<<" ";
        //print

        int i=0;int j=i+g;
        while(j<n1+n2)
        {
            if(i<n1 && j<n1)
            {
                if(N1[i]>N1[j])
                {
                    //swap
                    int temp = N1[i];
                    N1[i]=N1[j];
                    N1[j]=temp;
                }
            }
            else if (i<n1 && j>=n1)
            {
                if(N1[i]>N2[j-n1])
                {
                    //swap
                    int temp = N1[i];
                    N1[i]=N2[j-n1];
                    N2[j-n1]=temp;
                }
            }
            else
            {
                if(N2[i-n1]>N2[j-n1])
                {
                    //swap
                    int temp = N2[i-n1];
                    N2[i-n1]=N2[j-n1];
                    N2[j-n1]=temp;
                }
            }
            //Print
            cout<<"\n     i= "<<i<<"  j= "<<j;
            cout<<"\n     N1 = ";
            for(int i=0;i<n1;i++)
                cout<<N1[i]<<" ";
            cout<<"\n     N2 = ";
            for(int i=0;i<n2;i++)
                cout<<N2[i]<<" ";
            //print

            i++;j++;
        }
        if(g==1)
            break;
    }
}


int main()
{
    int A1[] = {12,42};
    int A2[] = {3,4,5,28,37,42,43,46};
    Merge(A1,A2,2,8);

    cout<<"After Merge : "<<endl;

    cout<<"\nN1 = ";
    for(int i=0;i<2;i++)
        cout<<A1[i]<<" ";

    cout<<"\nN2 = ";
    for(int i=0;i<8;i++)
        cout<<A2[i]<<" ";
    return 0;

}
