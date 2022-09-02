 #include<bits/stdc++.h>
 using namespace std;

 void swap(int a[], int i, int j)
    {
        int temp;
        temp = a[i];
        a[i]= a[j];
        a[j]= temp;
    }

    void sort012(int a[], int n)
    {
      int c=0, i=0, j=n-1;
      while(c<=j)
      {
          if(a[c]==0)
          {
              swap(a,c,i);
              c++;i++;
          }
          else if(a[c]==1)
          {
              c++;
          }
          else
          {
              swap(a,c,j);
              j--;
          }
      }
    }

    int main()
    {
        int A[6]={2,1,0,0,1,0};
        sort012(A,6);
        for(int i=0;i<6;i++)
            cout<<A[i]<<" ";

    }
