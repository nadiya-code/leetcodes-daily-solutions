class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
                ans+=2;
            }
            else{
                if(i+1<n && s[i+1]==')'){
                    i++;
                }
                else{
                    ans++;
                }
                if(!st.empty()){
                    st.pop();
                    ans-=2;
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
    }
};