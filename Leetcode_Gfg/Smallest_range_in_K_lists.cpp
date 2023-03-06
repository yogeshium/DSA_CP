//Smallest range in K lists

#include<bits/stdc++.h>
using namespace std;

    class Element
    {
        public:
        int data;
        int i;
        int j;

        Element(int d, int I, int J)
        {
            data = d;i=I;j=J;
        }
    };
    class comparator{
        public:
        bool operator() (const Element* e1, const Element* e2)
        {
            return e1->data > e2->data;
        }
    };



    pair<int,int> findSmallestRange(int A[][N], int n, int k)
    {
          pair<int,int> ans = make_pair(0,100000);

          priority_queue<Element*, vector<Element*>, comparator> minHeap;

          Element *range_max = new Element(0,-1,-1);

          for(int i=0;i<k;i++)
          {
              Element *ptr= new Element(A[i][0], i, 0);

              if(ptr->data>range_max->data)
              {
                  range_max = ptr;
              }
              minHeap.push(ptr);
          }

          while(!minHeap.empty())
          {
              Element* range_min = minHeap.top();
              minHeap.pop();

              //cout<<"range_max : "<<range_max->data<<" "<<range_max->i<<" "<<range_max->j<<endl;
              //cout<<"range_min : "<<range_min->data<<" "<<range_min->i<<" "<<range_min->j<<endl<<endl;

              if(range_max->data-range_min->data < ans.second-ans.first)
              {
                  ans.first = range_min->data;
                  ans.second = range_max->data;
              }

              if(range_min->j+1<n)
              {
                  Element* obj = new Element(A[range_min->i][range_min->j+1], range_min->i, range_min->j+1);
                  if(obj->data>range_max->data)
                  {
                      range_max = obj;
                  }
                  minHeap.push(obj);
              }
              else
                break;
          }
          return ans;
