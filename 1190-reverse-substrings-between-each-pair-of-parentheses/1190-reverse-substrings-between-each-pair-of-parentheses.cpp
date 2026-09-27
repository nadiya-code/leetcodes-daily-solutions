class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string t="";
        for(int i=0;i<n;i++){
            if(s[i]!='('){
                t+=s[i];
            }
            else{
                int j=i+1;
                int count=1;
                while(j<n && count>0){
                    if(s[j]=='('){
                        count++;
                    }
                    else if(s[j]==')'){
                        count--;
                    }
                    j++;
                }
                string sub=s.substr(i+1,j-i-2);
                string reversed=reverseParentheses(sub);
                reverse(reversed.begin(),reversed.end());
                t+=reversed;
                i=j-1;
            }
        }
        return t;
    }
};