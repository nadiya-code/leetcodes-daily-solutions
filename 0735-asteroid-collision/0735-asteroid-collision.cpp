class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()){
                st.push(asteroids[i]);
            }
            else if(!st.empty() && st.top()>0 && asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else if(!st.empty() && st.top()>0 && asteroids[i]<0){
                if(st.top()<abs(asteroids[i])){
                    while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                        st.pop();
                    }
                    if(!st.empty() && st.top()==abs(asteroids[i])){
                        st.pop();
                    }
                    else if(st.empty()||(!st.empty()&& st.top()<0)){
                        st.push(asteroids[i]);
                    }
                }
                else if(st.top()==abs(asteroids[i])){
                    st.pop();
                }
            }
            else if(!st.empty() && ((st.top()<0 && asteroids[i]>0)||(st.top()<0 && asteroids[i]<0))){
                st.push(asteroids[i]);
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