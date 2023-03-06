//TRIE IMPLEMENTATION

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
        data=ch;
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal = false;
    }
};

class Trie
{
    TrieNode* root;
public:
    Trie()
    {
        root= new TrieNode('\0');
    }

    //INSERTION
    void Insert(TrieNode* root, string s, int i)
    {
        if(i>=s.size())
        {
            root->isTerminal = true;
            return;
        }
        int index = s[i]-'A';
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

    void insertWord(string word)
    {
        Insert(root, word, 0);
    }

    //SEARCHING
    bool Search(TrieNode* root, string s, int i)
    {
        if(i>=s.size())
        {
            return root->isTerminal;
        }

        int index = s[i]-'A';
        //present
        if(root->children[index]!=NULL)
            return Search(root->children[index],s,i+1);
        return false;
    }

    bool searchWord(string word)
    {
        return Search(root, word, 0);
    }


    //Removing
    //Way1:
    /*
    void Remove(TrieNode* root, string s, int i)
    {
        if(i>=s.size())
        {
            root->isTerminal = false;
        }

        int index = s[i]-'A';

        if(root->children[index]!=NULL)
            Remove(root->children[index],s,i+1);
        return;
    }
    */
    //way 2:
    TrieNode* Remove(TrieNode* root, string s, int i)
    {
        if(i>=s.size())
        {
            if(root->isTerminal)
            {
                delete root;
                return NULL;
            }
            else
            {root->isTerminal = false;
                return root;
            }
        }

        int index = s[i]-'A';

        if(root->children[index]!=NULL)
            root->children[index] = Remove(root->children[index],s,i+1);

        return root;
    }

    void removeWord(string word)
    {
        Remove(root,word,0);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("YOGESH");
    t->insertWord("YOGES");
    t->insertWord("ABX");

    cout<<t->searchWord("YOGESH");
    t->removeWord("YOGESH");
    cout<<"\n"<<t->searchWord("YOGESH");
}







//LEETCODE Implementation

/*
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

    bool StartsWith(TrieNode* root, string s, int i)
    {
       if(i>=s.size())
        {
            return true;
        }

        int index = s[i]-'a';
        //present
        if(root->children[index]!=NULL)
            return StartsWith(root->children[index],s,i+1);
        return false;
    }

    bool startsWith(string prefix)
    {
        return StartsWith(root,prefix,0);
    }
};
*/
