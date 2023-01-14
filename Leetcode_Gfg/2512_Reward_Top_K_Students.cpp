#include<bits/stdc++.h>
using namespace std;



//Approach : using heap
 int CalculateMarks(string input, unordered_map<string,bool>& p, unordered_map<string,bool>& n)
    {
        int m=0;string temp;
        for(int i=0;i<input.size();i++)
        {
            if(input[i]==' ')
            {
                if(p.find(temp)!=p.end())
                    m=m+3;
                else if(n.find(temp) != n.end())
                    m=m-1;
                temp.erase();
            }
            else
            {
                temp.push_back(input[i]);
            }
        }
        if(p.find(temp)!=p.end())
            m=m+3;
        else if(n.find(temp) != n.end())
            m=m-1;
        temp.erase();

        return m;

    }

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k)
    {
       pair<int,int> id_marks;
        stack<pair<int,int>> List;

        unordered_map<string,bool> pos,neg;
        for(int i=0;i<positive_feedback.size();i++)
        {
            pos[positive_feedback[i]]=true;
        }
        for(int i=0;i<negative_feedback.size();i++)
        {
            neg[negative_feedback[i]]=true;
        }
        vector<pair<int,int>> ans;
        for(int i=0;i<student_id.size();i++)
        {
            ans.push_back(make_pair(CalculateMarks(report[i],pos,neg), student_id[i]));
        }

        //How to sort vector pair ( which have multiple conditions)
            // [&]-  Lambda expression in C++ (read in gfg)
         sort(ans.begin(), ans.end(), [&](auto& a, auto& b) {
            return a.first > b.first || a.first == b.first && a.second < b.second;
        });



        vector<int> res;

        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].second);
        }
        return res;
    }






/*
// My Approach : (Got TLE 24/26 testcases)

void show(stack<pair<int,int>> List)
{
    while(!List.empty())
   {
       cout<<"\nFirst = "<<List.top().first<<" Second = "<<List.top().second;
        List.pop();
   }
   cout<<endl<<endl;
}

 int CalculateMarks(string input, unordered_map<string,bool>& p, unordered_map<string,bool>& n)
    {
        int m=0;string temp;
        for(int i=0;i<input.size();i++)
        {
            if(input[i]==' ')
            {
                if(p.find(temp)!=p.end())
                    m=m+3;
                else if(n.find(temp) != n.end())
                    m=m-1;
                temp.erase();
            }
            else
            {
                temp.push_back(input[i]);
            }
        }
        if(p.find(temp)!=p.end())
            m=m+3;
        else if(n.find(temp) != n.end())
            m=m-1;
        temp.erase();

        return m;

    }

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k)
    {
       pair<int,int> id_marks;
        stack<pair<int,int>> List;

        unordered_map<string,bool> pos,neg;
        for(int i=0;i<positive_feedback.size();i++)
        {
            pos[positive_feedback[i]]=true;
        }
        for(int i=0;i<negative_feedback.size();i++)
        {
            neg[negative_feedback[i]]=true;
        }

        for(int i=0;i<student_id.size();i++)
        {
            id_marks.first=student_id[i];
            id_marks.second= CalculateMarks(report[i],pos,neg);

            cout<<"\nComing id_marks = "<<id_marks.first<<"  "<<id_marks.second;
            cout<<"\nList : ";
            show(List);

            if(List.empty())
            {
                List.push(id_marks);
            }
            else if(List.top().second<id_marks.second)
            {
                List.push(id_marks);
            }
            else if(List.top().second>=id_marks.second)
            {
                vector<pair<int,int>> tempArray;
                while(List.top().second>id_marks.second || (List.top().second == id_marks.second && List.top().first<id_marks.first))
                {
                    tempArray.push_back(List.top());
                    List.pop();
                    if(List.empty())
                        break;
                }
                List.push(id_marks);
                for(int i=tempArray.size()-1;i>=0;i--)
                {
                    List.push(tempArray[i]);
                }
            }
        }

        vector<int> ans;int i=0;
        while(i<k)
        {
            ans.push_back(List.top().first);
            List.pop();
            i++;
        }
        return ans;
    }

*/





int main()
{

    vector<string> p = {"fkeofjpc","qq","iio"};
    vector<string> n = {"jdh","khj","eget","rjstbhe","yzyoatfyx","wlinrrgcm"};
    vector<string> res = {"rjstbhe eget kctxcoub urrmkhlmi yniqafy fkeofjpc iio yzyoatfyx khj iio","gpnhgabl qq qq fkeofjpc dflidshdb qq iio khj qq yzyoatfyx","tizpzhlbyb eget z rjstbhe iio jdh jdh iptxh qq rjstbhe","jtlghe wlinrrgcm jnkdbd k iio et rjstbhe iio qq jdh","yp fkeofjpc lkhypcebox rjstbhe ewwykishv egzhne jdh y qq qq","fu ql iio fkeofjpc jdh luspuy yzyoatfyx li qq v","wlinrrgcm iio qq omnc sgkt tzgev iio iio qq qq","d vhg qlj khj wlinrrgcm qq f jp zsmhkjokmb rjstbhe"};
    vector<int> sid = {96537918,589204657,765963609,613766496,43871615,189209587,239084671,908938263};

    vector<int> ans = topStudents(p,n, res, sid, 3);

    cout<<"\n\n Ans = ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
