//Merge k Sorted Arrays

#include<bits/stdc++.h>
using namespace std;


//My Approach :
/*
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int, vector<int>, greater<int>> mh;

        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[i].size();j++)
                mh.push(arr[i][j]);
        }

        vector<int> res;
        while(!mh.empty())
        {
            res.push_back(mh.top());
            mh.pop();
        }
        return res;
    }
*/


//Approach 2: (Babbar)

class Element
    {
      public:
        int data;
        int i;
        int j;

        Element(int d, int I, int J)
        {
            data = d;
            i=I;j=J;
        }
    };
    class myComparator
    {
    public:
        bool operator() (const Element* e1, const Element* e2)
        {
            return e1->data > e2->data;
        }
    };

    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<Element*, vector<Element*>, myComparator> mh;

        //pushing starting element of every row in matrix
        for(int i=0;i<arr.size();i++)
        {
            Element *obj = new Element(arr[i][0], i, 0);
            mh.push(obj);
        }

        while(!mh.empty())
        {

            Element *obj = mh.top();
            mh.pop();
            ans.push_back(obj->data);

            if(obj->j+1<arr[obj->i].size())
            {
                Element *temp = new Element(arr[obj->i][obj->j+1], obj->i, obj->j+1);
                mh.push(temp);
            }
        }

        return ans;
    }








int main()
{
    vector<vector<int>> A={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = mergeKArrays(A,3);

    cout<<"\n\n Answer: ";
    for(auto i:ans)
        cout<<i<<" ";
}
