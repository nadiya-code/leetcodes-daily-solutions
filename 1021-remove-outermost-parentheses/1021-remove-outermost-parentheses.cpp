class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string valid="";
        int count=0;
        for(char c:s){
            if(c=='('){
                if(count>0){
                    valid+=c;
                }
                count++;
            }
            else{
                count--;
                if(count>0){
                    valid+=c;
                }
            }
        }
        return valid;
    }
};