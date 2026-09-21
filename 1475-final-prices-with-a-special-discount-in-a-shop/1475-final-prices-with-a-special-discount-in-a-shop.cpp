class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int m=prices.size();
        st.push(prices[m-1]);
        for(int i=m-2;i>=0;i--){
            int x=prices[i];
            while(!st.empty()&& st.top()>x){
                st.pop();
            }
            if(!st.empty()){
               prices[i]-=st.top();
            }
            st.push(x);
        }
        return prices;
    }
};