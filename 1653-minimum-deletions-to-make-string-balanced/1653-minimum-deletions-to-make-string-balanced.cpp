class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int removed=0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                st.pop();
                removed++;
            }
            else{
                st.push(s[i]);
            }
        }
        return removed;
    }
};