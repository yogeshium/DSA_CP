#include<bits/stdc++.h>
using namespace std;


class SGTree
{
  public:
  vector<int> seg;

  SGTree(int n, int arr[])
  {
    seg.resize(4*n+1);
    build(0,0,n-1,arr);
  }

  void build(int idx, int low, int high, int arr[])
  {
    if(low==high)
    {
      seg[idx]=arr[low];
      return ;
    }
    int mid=low+(high-low)/2;
    build(2*idx+1,low,mid,arr);
    build(2*idx+2,mid+1,high,arr);

    seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
  }

  int query(int idx,int low, int high, int l, int r)
  {
    //no overlap
    //(l r) (low high) or (low high)(lr)
    if(r<low || high<l)
    {
      return INT_MAX;
    }

    //complete overlap
    //(l low high r)
    if(low >= l && high<=r)
      return seg[idx];

    //partial overlap
    int mid=low+(high-low)/2;
    int left = query(2*idx+1,low,mid,l,r);
    int right = query(2*idx+2,mid+1,high,l,r);

    return min(left,right);
  }


  void update(int idx, int low, int high, int i, int val)
  {
    if(low==high)
    {
      seg[idx]=val;
      return ;
    }

    int mid=(low+high)/2;
    if(i<=mid)
      update(2*idx+1,low,mid,i,val);
    else
      update(2*idx+2,mid+1,high,i,val);

    seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
  }
};


int main()
{
  int arr[]={2,4,5,3,1};
  SGTree s(5,arr);

  for(int i=0;i<s.seg.size();i++)
    cout<<s.seg[i]<<" ";
}
