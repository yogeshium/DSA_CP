//14. Longest Common Prefix
#include<bits/stdc++.h>
using namespace std;

//Approach 1 :
/*
ek character uthao and saare string se match karao
-> agr hogya to ans mai push_back
-> nahi hua to ans ko return
*/

//Approach 2 : using Trie
/*
    //Babbar : same approach bas usne childCount naam ka bhi rakha h Trie mai

    //MyApproach : mai humesha check kr rha ki ek hi child h ki ni by traversing 26 childrens

*/
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

    bool Search(TrieNode* root, string s, int i)
    {
        if(i>=s.size())
        {
            return root->isTerminal;
        }

        int index = s[i]-'a';
        //present
        if(root->children[index]!=NULL)
            return Search(root->children[index],s,i+1);
        return false;
    }

    bool search(string word)
    {
        return Search(root, word, 0);
    }


//Longest Common Prefix : main fuction:
    void findCommon(TrieNode* root, string& ans)
    {
        int index=-1;
        for(int i=0;i<26;i++)
        {
            if(root->children[i]!=NULL)
            {
                if(index==-1 && root->isTerminal==false)
                    index = i;
                else
                    return;
            }
        }
         if(index==-1)
            return;
        ans.push_back('A'+index);
        findCommon(root->children[index],ans);
    }

    string LongestCommonPrefix()
    {
        string ans="";
        findCommon(root,ans);
        return ans;
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("YOGESH");
    t->insertWord("YOGE");

    cout<<t->LongestCommonPrefix();
}





//LEETCODE Implementation

/*

};
*/
