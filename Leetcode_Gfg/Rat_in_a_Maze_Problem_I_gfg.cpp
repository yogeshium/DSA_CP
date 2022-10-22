#include<bits/stdc++.h>
using namespace std;

// My Approach (or u can say My Code)
    /*Iss Question mai Lexicographically increasing order mai paths ko return krna tha , lekin
    mene aesa code hi likh diya hai ki ye apne aap ho rha hai.
    Actually mai lexicographically hi dekh rha hu like : pehle U (jo generally false ho jata hai)
    then D, then L , then R;
    Jabki Babbar ne last mai sort kiya hai taki lexicographical order mai aa jaye;
    */
   void go(vector<vector<int>>& In, int i, int j, int n, vector<string>& Out, string& temp)
    {
        if(i<0 || j<0 || i>=n || j>=n)
           {
               temp.pop_back();
               return ;
           }

        if((i==n-1) && (j==n-1) && (In[n-1][n-1]==1))
        {
            Out.push_back(temp);
            temp.pop_back();
            return ;
        }
        if(In[i][j]==0 || In[i][j]==-1)
           {
               temp.pop_back();
               return ;
           }
        //Kyuki ab hum aage badh rhe to jis area mai hai abhi usko hum
        //Visited Mark krdenge
        In[i][j]=-1;

        temp.push_back('U');
        go(In,i-1,j,n,Out,temp);
        temp.push_back('D');
        go(In,i+1,j,n,Out,temp);
        temp.push_back('L');
        go(In,i,j-1,n,Out,temp);
        temp.push_back('R');
        go(In,i,j+1,n,Out,temp);

        //Chuki isne sare direction dekh liye , to ab ye jis direction se aya tha
        //iss position pe usko bhi to hatana parega bcz function to khatam hone
        //wala hai , mtlb ye vala position se bhi to hm hatne wale hai
        temp.pop_back();

        //Jab humara function return karega to hum uss area ko
        //Unvisited mark krdenge
        In[i][j]=1;// Vapis 1 banana parega na or paths ko check krne ke liye
    }


    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string temp="";
        go(m, 0,0,n,ans,temp);

        if(ans.size()<1)
            ans.push_back("-1");
        return ans;
    }

int main()
{
    vector<vector<int>> m= {{1, 0},{1,0}};
    vector<string> ans = findPath(m,2);
    cout<<" \n Ans : ";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
