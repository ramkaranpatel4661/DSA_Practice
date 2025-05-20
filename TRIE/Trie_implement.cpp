#include<iostream>
using namespace std;
class trieNode{
    public:
      char value;
      trieNode* children[26];
      bool isterminal;
    
    trieNode(char val){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->value=val;
        this->isterminal=false;
    }


    
};
void InsertWord(trieNode * root , string word){
   //base case 
   //cout<<"recieved "<<word <<"   for insertion "<<endl;
   if(word.length()==0){
     root->isterminal=true;
     return; 
   }
   char ch=word[0];
   int index=ch-'a';
   trieNode* child;
   if(root->children[index] !=NULL){
       child = root->children[index];
   }
   else{
       child =new trieNode(ch);
       root->children[index]=child;
   }
    InsertWord(root->children[index],word.substr(1));
}
bool search(trieNode*root,string word){
    if(word.length()==0){
        return root->isterminal;
    }
    char ch =word[0];
    int index=ch-'a';
    trieNode*child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return false;
    }
    return search(child,word.substr(1));
}
void delet(trieNode*root,string word){
   if(word.length()==0){
    root->isterminal=false;
    return;
   }
   char ch=word[0];
   int index=ch-'a';
   trieNode*child;
   if(root->children[index]!=NULL){
    child=root->children[index];
   }
   else{
    return;
   }
   delet(child,word.substr(1));
}
int main(){
    trieNode * root = new trieNode('-');
    // cout<<"enter the number string you want to enter :"<<endl;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cout<<"enter string : "<<endl;

    //     string s;
    //     cin>>s;
    //     InsertWord(root,s);

    // }  
    InsertWord(root,"love");
    InsertWord(root,"ram");
    InsertWord(root,"karan");
    if(search(root,"ram")){
        cout<<"found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    delet(root,"ram");
     if(search(root,"ram")){
        cout<<"found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }

    return 0;
}