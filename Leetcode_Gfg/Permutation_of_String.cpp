#include <bits/stdc++.h>
using namespace std;

void Permutation_of_String(string s,string t, int i, int n, vector<string>& res)
    {
        if(i>=n)
        {
            res.push_back(t);
            return ;
        }
        for(int j=i;j<n;j++)
        {
            //swap(s[i],s[j])
                char temp = s[i];
                s[i]=s[j];
                s[j]=temp;
            t.push_back(s[i]);
            cout<<"\n j= "<<j<<" i= "<<i<<" s= "<<s<<" t= "<<t;
            Permutation_of_String(s,t,i+1,n,res);
            t.pop_back();
            //swap(s[i],s[j])
                temp = s[i];
                s[i]=s[j];
                s[j]=temp;
        }
    }

int main()
{
	vector<string> res;
	Permutation_of_String("ab","",0,2,res);
    cout<<"\n\n\n";
	for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}
