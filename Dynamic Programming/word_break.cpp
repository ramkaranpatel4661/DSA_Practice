class TrieNode{
    public:
    bool flag;
    TrieNode*children[26];
    TrieNode(){
        flag=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }

    }
};
class Solution {
private:
 TrieNode * root;
public:
    Solution(){
        root=new TrieNode();
    }
    void insert(vector<string>&wordDict){
        for(auto word:wordDict){
            TrieNode*curr=root;
            for(auto i:word){
                int index=i-'a';
                if(curr->children[index]==NULL){
                    curr->children[index]=new TrieNode();
                }
                curr=curr->children[index];
            }
            curr->flag=true;
        }
    }
    bool bytrie(string &s){
        vector<int>dp(s.length()+1,0);
        dp[0]=1;
        for(int i=0;i<s.length();i++){
            if(dp[i]==0){continue;}
            TrieNode*curr=root;
            for(int j=i;j<s.length();j++){
                int index=s[j]-'a';
                if(curr->children[index]==NULL){
                    break;
                }
                curr=curr->children[index];
                if(curr->flag==true){
                    dp[j+1]=1;
                    }
                }
            }
        
        return dp[s.length()];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        insert(wordDict);
        return bytrie(s);
    }
};