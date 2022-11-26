//Palindrome by Splitting
//Problem Code: SPLITPAL

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    deque<int> A;
	    for(int i=0;i<n;i++)
	    {
	        int temp;cin>>temp;
	        A.push_back(temp);
	    }
	    int ans=0;
	    while(A.size()>1)
	    {
	        if(A.front() == A.back())
	        {
	            A.pop_front();A.pop_back();
	        }
	        else if(A.front() > A.back())
	        {
	            ans++;

	            int temp = A.front();
	            A.pop_front();
	            A.push_front(temp-A.back());
	            A.pop_back();
	        }
	        else
	        {
	            ans++;
	            int temp = A.back();
	            A.pop_back();
	            A.push_back(temp-A.front());
	            A.pop_front();
	        }
	    }
	    cout<<ans<<endl;
	}

	return 0;
}

