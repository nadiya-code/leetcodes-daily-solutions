class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int m=prices.size();
        vector<int>small(prices.begin(),prices.end());
        st.push(prices[m-1]);
        for(int i=m-2;i>=0;i--){
            while(!st.empty()&& st.top()>prices[i]){
                st.pop();
            }
            if(!st.empty()){
               small[i]-=st.top();
            }
            st.push(prices[i]);
        }
        return small;
    }
};