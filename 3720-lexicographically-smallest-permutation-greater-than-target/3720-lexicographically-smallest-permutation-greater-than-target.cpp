class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        multiset<char>st(s.begin(),s.end());
        int n=target.size();
        string ans="";
        for(int i=0;i<n;i++){
            auto it=st.find(target[i]);
            if(it!=st.end()){
                ans+=target[i];
                st.erase(it);
            }
            else{
                auto bigger=st.upper_bound(target[i]);
                if(bigger!=st.end()){
                    ans+=*bigger;
                    st.erase(bigger);
                    for(auto ch:st){
                        ans+=ch;
                    }
                    return ans;
                }
                break;
            }
        }
        for(int i=ans.size()-1;i>=0;i--){
            st.insert(ans[i]);
            auto bigger= st.upper_bound(ans[i]);
            if(bigger!=st.end()){
                ans=ans.substr(0,i);
                ans+=*bigger;
                st.erase(bigger);
                for(auto &c:st){
                    ans+=c;
                }
                return ans;
            }
        }
        return "";
    }
};