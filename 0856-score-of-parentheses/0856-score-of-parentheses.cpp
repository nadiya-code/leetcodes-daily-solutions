class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                int count=1;
                int j=i+1;
                while(j<n && count>0){
                    if(s[j]=='('){
                        count++;
                    }
                    else{
                        count--;
                    }
                    j++;
                }
                if(i+1==j-1){
                    ans+=1;
                }
                else{
                    string inside=s.substr(i+1,j-i-2);
                    ans+=2*scoreOfParentheses(inside);
                }
                i=j-1;
            }
        }
        return ans;
    }
};