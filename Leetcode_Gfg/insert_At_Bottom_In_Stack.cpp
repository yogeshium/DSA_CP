#include<bits/stdc++.h>
using namespace std;


void insertAtBottom(stack<int> &st,int x)
    {
        if(st.empty())
         { st.push(x);  return;}
        int temp = st.top();st.pop();
        insertAtBottom(st,x);
        st.push(temp);
    }

