//MaxHeap and MinHeap

//* IMPORTANT : 1 based index pe h ye pura   *///

#include<bits/stdc++.h>
using namespace std;

//MaxHeap

class maxHeap{
    int A[100];
    int Size;
public:
    maxHeap()
    {
        A[0]=-1;
        Size=0;
    }
    void Push(int d)
    {
        Size=Size+1;
        int index=Size;
        A[index]=d;

        //Kind of Heapify ( Bottom to Top)
        while(index>1)
        {
            int parent = index/2;
            if(A[parent]<A[index])
            {
                //swap
                int temp = A[parent];
                A[parent]=A[index];
                A[index]=temp;

                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void Pop()
    {
        A[1]=A[Size];
        Size--;

        //Kind of Heapify (Top to Bottom)
        int i=1;
        while(i<=Size)
        {
            int largest = i;
            int left = 2*i, right =2*i+1;

            if(left<=Size && A[largest]<A[left])
                largest=left;
            if(right<=Size && A[largest]<A[right])
                largest = right;

            if(largest!=i)
            {
                int temp = A[largest];
                A[largest]=A[i];
                A[i]=temp;

                i=largest;
            }
            else
                return;
        }
    }

    int top()
    {
        if(Size==0)
            return -1;
        return A[1];
    }

    void print()
    {
        cout<<"\n";
        for(int i=1;i<=Size;i++)
            cout<<A[i]<<" ";
    }

    void heapify(int A[], int i, int Size)
    {
        int largest = i;
        int left = 2*i, right = 2*i+1;

        if(left<=Size && A[largest]<A[left])
            largest = left;

        if(right<=Size && A[largest]<A[right])
            largest = right;

        if(largest!=i)
        {
            //swap
            int temp =A[largest];
            A[largest]=A[i];
            A[i]=temp;

            heapify(A,largest,Size);
        }

    }

    void buildHeap(int A[], int n)
    {
        for(int i=n/2;i>=0;i--)
        {
            heapify(A,i,n);
        }
    }
};


//MinHeap
class minHeap
{

            int *A;
            int Size;
        public:

            minHeap(int n)
            {
                A=new int[n+1];
                Size=0;
            }

            void Push(int d)
            {
                Size++;
                A[Size]=d;

                if(Size==1)
                    return;

                int i=Size;
                while(i>1)
                {
                    int parent = i/2;
                    if(A[parent]>A[i])
                    {
                        //swap
                        int temp = A[parent];
                        A[parent]=A[i];
                        A[i]=temp;

                        i=parent;
                    }
                    else
                        break;
                }
            }

            void Pop()
            {
                if(Size==0)
                    return;
                A[1]=A[Size];
                Size--;

                int i=1;
                while(i<=Size)
                {
                    int smallest = i;
                    int left = 2*i , right = 2*i+1;
                    if(left<=Size && A[left]<A[smallest])
                        smallest = left;

                    if(right<=Size && A[right]<A[smallest])
                        smallest = right;

                    if(smallest!=i)
                    {
                        //swap
                        int temp = A[i];
                        A[i]=A[smallest];
                        A[smallest]=temp;

                        i=smallest;
                    }
                    else
                        return;
                }
            }

            void print()
             {
                 for(int i=1;i<=Size;i++)
                    cout<<A[i]<<" ";
                 cout<<"\n";
             }

             bool isEmpty()
            {
                if(Size==0)
                    return false;
                return true;
            }

            int top()
            {
                return A[1];
            }
};


int main()
{
    return 0;
}
