class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n<=k){
            return "0";
        }
        string s="";
        stack<char>st;
        for(int i=0;i<n;i++){
            while(k>0 && !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        if(k>0){
            s=s.substr(0,s.size()-k);
        }
        int i=0;
        while(i<s.size() && s[i]=='0'){
            i++;
        }
        s=s.substr(i);
        return s.empty()? "0":s;
    }
};