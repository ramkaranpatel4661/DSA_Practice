class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int len=0;
        bool flag=false;
        for(auto i:m){
            if((i.second)%2==0){
                len+=i.second;
            }
            else{
                flag=true;
                len+=i.second-1;
            }
        }
        return flag==true ? len+1 : len;
    }
};