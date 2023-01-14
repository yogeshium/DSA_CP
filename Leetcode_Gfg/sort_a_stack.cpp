#include<bits/stdc++.h>
using namespace std;

void Sorted_Way_Insert(int d, stack<int>&s)
{
    if(s.empty())
    {    s.push(d);return;}
    if(d>=s.top())
    {    s.push(d);return;}

    int temp = s.top();
    s.pop();
    Sorted_Way_Insert(d,s);
    s.push(temp);
}

void Sort(stack<int>& s)
{
    if(s.empty())
        return;
    int d = s.top();
    s.pop();
    Sort(s);
    Sorted_Way_Insert(d,s);
}
