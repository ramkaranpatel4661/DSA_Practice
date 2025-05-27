class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal){
            return true;
        }
        string temp="";
        for(int i=1;i<s.length();i++){
            temp=s.substr(i)+s.substr(0,i);
            if(temp==goal){
                return true;
            }
        }
        return false;
    }
};