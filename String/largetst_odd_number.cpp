class Solution {
public:
    string largestOddNumber(string num) {
        while(!num.empty()){
            if(int(num[num.size()-1])%2!=0){
                return num;
            }
            num.pop_back();

        }
        return  "";
    }
};