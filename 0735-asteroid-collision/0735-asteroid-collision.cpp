class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int & asteroid : asteroids){
            if(!st.empty() && asteroid<0 ){
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroid)){
                    st.pop();
                }
                if(!st.empty() && st.top()>0 && st.top()==abs(asteroid)){
                    st.pop();
                }
                else if(st.empty()||st.top()<0){
                    st.push(asteroid);
                }
            }
            else{
                st.push(asteroid);
            }
        }
        int size=st.size();
        vector<int>ans(size);
        size--;
        while(!st.empty()){
            ans[size--]=st.top();
            st.pop();
        }
        return ans;
    }
};