#include<bits/stdc++.h>
using namespace std;

//Same Aproach (in discussion) but 100% fast code

/*
    void nextPermutation(vector<int>& nums) {
        // support variables
        int i = nums.size() - 2, j = i + 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        // edge case: already the highest permutation you can get
        if (i == -1) {
            reverse(begin(nums), end(nums));
            return;
        }
        // finding the first element > nums[i]
        while (nums[--j] <= nums[i]);
        // swapping i and j's values
        swap(nums[i], nums[j]);
        // ordering the rest
        sort(begin(nums) + i + 1, end(nums));
    }

*/

//My Aproach 30% fast code 10ms
    void change(vector<int>& A, int p,int n)
    {
    /*    cout<<"\nbefore change func\n";
        for(int i=0;i<A.size();i++)
        {
            cout<<A[i]<<" ";
        }
    */

        for(int i=n;i>=p;i--)
        {
            if(A[i]>A[p])
            {
                int temp = A[i];
                A[i]=A[p];
                A[p] = temp;
                 break;
            }
        }

     /*   cout<<"\nafter change func\n";
        for(int i=0;i<A.size();i++)
        {
            cout<<A[i]<<" ";
        }
        */
    }

    void revers(vector<int>&A,int p1,int p2)
    {

    /*    cout<<"\nbefore reverse func\n";
        cout<<"\n P1 = "<<p1<<" p2 = "<<p2<<"\n";
        for(int i=0;i<A.size();i++)
        {
            cout<<A[i]<<" ";
        } */

        while(p1<p2)
        {
                int temp = A[p1];
                A[p1]=A[p2];
                A[p2] = temp;
                p1++;p2--;
        }

        /*
         cout<<"\nafter reverse func\n";
        for(int i=0;i<A.size();i++)
        {
            cout<<A[i]<<" ";
        }
        */
    }

    void nextPermutation(vector<int>& A) {
        bool flag = false;
        int n= A.size();
        for(int i=n-1;i>0;i--)
        {
            if(A[i]>A[i-1])
            {
                change(A,i-1,n-1);
                revers(A,i,n-1);

                flag=true;
                break;
            }
        }
        if(flag==false)
            revers(A,0,n-1);

    }


    int main()
    {

        vector<int> A = {1,3,5,2,1};
        nextPermutation(A);

        cout<<"\nNext Permutation\n";
        for(int i=0;i<A.size();i++)
        {
            cout<<A[i]<<" ";
        }
    }

//Aproacb =
/*
First of all, we will create 2 support variables, our indexes i and j,
respectively set to be pointing to the penultimate element and past the
end of the vector.

We will then keep reducing i as long as it is non-negative and as
long as it points to an element >= than the previous one.

If we were to finally end up with i == -1, it would mean that the
whole vector is set in decreasing order, so no next
permutation is possible, and we need to transform the array to the
very first one, before leaving the function.

Now, you might just opt to sort the vector, but since we know it is
already ordered, just reversing it might just save us precious
computation: O(nlogn) vs. O(n) (or, rather O(n/2)) is a no brainer.

For any other value of i, we will then search with j for the very
first element that is <= nums[i], which is guaranteed to be
there (since all the elements before i are in decreasing order).

Once found, we will swap nums[i] and nums[j], since nums[j] is the
next number to go there, and set the rest of the positions
from i + 1 to be in increasing order - I guess here reversing and
then using insertion sort would perform better, but I did not feel
like going for that overkill just in case.
*/
