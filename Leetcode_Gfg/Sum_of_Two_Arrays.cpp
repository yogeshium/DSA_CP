#include<bits/stdc++.h>
using namespace std;

	vector<int> findSum(vector<int> &a, vector<int> &b) {

	    vector<int> ans;
	    int carry =0, sum =0, i,j;
	    i=a.size()-1;j=b.size()-1;

	    while(i>=0 && j>=0)
	    {
	        int val1 = a[i];
	        int val2 = b[j];
	        sum = val1 + val2 + carry;

	        carry = sum/10;
	        sum = sum%10;
	        ans.push_back(sum);
	        i--;j--;
	    }

	    //When Left array is bigger
	    while(i>=0)
	    {
	        sum = a[i] + carry;
	        carry = sum/10;
	        sum = sum%10;
	        ans.push_back(sum);
	        i--;
	    }

	    //when right array is bigger
	    while(j>=0)
	       {
	           sum = b[j] + carry;
	           carry = sum/10;
	           sum = sum%10;
	            ans.push_back(sum);
	            j--;
	       }

	   //when last addition has carry left
	       while(carry != 0)
	       {
	           sum = carry;
	           carry = sum/10;
	           sum = sum%10;
	           ans.push_back(sum);
	       }
	    int p1=0, p2=ans.size()-1;
	    while(p1<p2)
        {
                int temp = ans[p1];
                ans[p1]=ans[p2];
                ans[p2] = temp;
                p1++;p2--;
        }

	    return ans;
	}

    int main()
    {
        vector<int> n1= {2,2,7,5,3,3};
        vector<int> n2= {4,3,3,8};
        vector<int> ans = findSum(n1, n2);
        cout<<"\nN1 : ";
        for(int i=0;i<n1.size();i++)
        {
            cout<<n1[i]<<" ";
        }
        cout<<"\nN2 : ";
        for(int i=0;i<n2.size();i++)
        {
            cout<<n2[i]<<" ";
        }
        cout<<"\nAnswer : ";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }

        return 0;
    }
