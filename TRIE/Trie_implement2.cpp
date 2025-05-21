#include<iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool end;

    TrieNode() {
        end = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i<word.length(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            if (curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
             //    cout<<"inserted character is "<<ch<<endl;

            }else{
               //  cout<<"already inserted this prefix : "<<ch<<endl;
            }
            curr = curr->children[index];
           
        }
        curr->end = true;
    }
    bool search(string word){
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int index=ch-'a';
            if(curr->children[index]==NULL){
                   return false;
            }
            
            curr = curr->children[index];
           if(i==word.length()-1 && curr->end==false){
                return false;
            }
        }
        cout<<"the search word is : "<<word<<endl;
        return true;
    }
    void delet(string word){
        TrieNode*curr=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int index=ch-'a';
            if(curr->children[index]==NULL){
                cout<<"the word is not present in the string so we can't delete "<<endl;
                return ;
            }
            curr=curr->children[index];
            if(i==word.length()-1){
                curr->end=false;
            }
        }
    }
    bool startswith(string word){
        TrieNode*curr=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int index=ch-'a';
            if(curr->children[index]==NULL){
                cout<<"enter preifx is not present : "<<endl;
                return false;
            }
            curr=curr->children[index];
        }
        cout<<"enter prefix is available :"<<endl;
        return true;
    }
};

int main() {
    
    Trie t;
    t.insert("the");
    t.insert("there");
    t.search("the");
   // t.search("ram");
   t.delet("the");
   if(t.search("the")){
      cout<<" not delted :"<<endl;
   }else{
    cout<<"deleted :"<<endl;
   }
   t.startswith("their");
    return 0;
}