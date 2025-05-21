#include <bits/stdc++.h> 
class TrieNode{
    public:
    TrieNode*children[26];
    int wordcount;
    int prefix;
    bool flag;
    TrieNode(){
        flag=false;
        prefix=0;
        wordcount=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie{
    private :
    TrieNode * root ;
    public:

    Trie(){
        // Write your code here.
        root =new TrieNode();
    }

    void insert(string &word){
        // Write your code here.
        TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int index=ch-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new TrieNode;
            }
            curr=curr->children[index];
            curr->prefix++;

        }
        curr->flag=true;
        curr->wordcount++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        TrieNode *curr=root;
          for(int i=0;i<word.size();i++){
            char ch=word[i];
            int index=ch-'a';
            if(curr->children[index]==NULL){
               return 0;
            }
            curr=curr->children[index];

        }
        return curr->wordcount;

    }

    int countWordsStartingWith(string &word){
        // Write your code here.
         TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int index=ch-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new TrieNode;
            }
            curr=curr->children[index];

        }
        return curr->prefix;
    }

    void erase(string &word){
        // Write your code here.
        TrieNode *curr = root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int index=ch-'a';
            if(curr->children[index]==NULL){
                return ;
            }
            curr=curr->children[index];
            curr->prefix--;
        }
        curr->flag=false;
        curr->wordcount--;

    }
};
