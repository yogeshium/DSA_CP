//Phone directory

#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal=false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }

    void Insert(TrieNode* root, string s, int i)
    {
        if(i>=s.size())
        {
            root->isTerminal = true;
            return;
        }
        int index = s[i]-'a';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        //Absent
        else
        {
            child = new TrieNode(s[i]);
            root->children[index]=child;
        }

        //Recursion sambhal lega
        Insert(child, s, i+1);
    }

    void insert(string word)
    {
        Insert(root, word, 0);
    }

    void AllTheWords(TrieNode* root, string s, vector<string>& ans)
    {
        if(root->isTerminal==true)
        {
            ans.push_back(s);
        }

        for(int i=0;i<26;i++)
        {
            if(root->children[i]!=NULL)
            {
                s.push_back('a'+i);
                AllTheWords(root->children[i],s,ans);
                s.pop_back();
            }
        }
    }

    void solve(TrieNode* root, string word, int i, vector<vector<string>>& result,string str="")
    {
        if(i>=word.size())
            return ;

        int index= word[i]-'a';
        if(root->children[index]!=NULL)
        {
            str.push_back(word[i]);

            vector<string> ans;

            AllTheWords(root->children[index],str,ans);

            result.push_back(ans);

            solve(root->children[index],word, i+1, result,str);
        }
        else
        {
            while(i<word.size())
            {
                vector<string> ans;
                ans.push_back("0");
                result.push_back(ans);
                i++;
            }
        }


    }

    vector<vector<string>> returnResult(string word)
    {
        vector<vector<string>> result;

        solve(root, word, 0, result);

        return result;
    }
};


//Main function;
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie* T= new Trie();
        //Insert Karo saare Elements ko pehle
        for(int i=0;i<n;i++)
            T->insert(contact[i]);

        //Ab solve krlo
        vector<vector<string>> result = T->returnResult(s);

        return result;
    }
