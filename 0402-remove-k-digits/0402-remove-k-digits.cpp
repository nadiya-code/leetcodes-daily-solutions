class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n<=k){
            return "0";
        }
        string st="";
        for(int i=0;i<n;i++){
            while(k>0 && !st.empty() && st.back()>num[i]){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        if(k>0){
            st=st.substr(0,st.size()-k);
        }
        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }
        st=st.substr(i);
        return st.empty()? "0":st;
    }
};