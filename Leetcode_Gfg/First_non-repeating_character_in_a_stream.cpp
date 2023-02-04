//First non-repeating character in a stream
#include<bits/stdio.h>
using namespace std;

string FirstNonRepeating(string s)
		{
		    string ans;
		    vector<int> A(26,0);
		    queue<char>q;
		    for(int i=0;i<s.size();i++)
		    {
		        A[s[i]-'a']++;

		        if(A[s[i]-'a']==1)
		            q.push(s[i]);

		        if(!q.empty())
		        {    while(A[q.front()-'a']>1)
		              {    q.pop(); if(q.empty()) break;}
		        }
		        if(q.empty())
		            ans.push_back('#');
		        else
		            ans.push_back(q.front());
		    }
		    return ans;
		}


int main()
{

}
