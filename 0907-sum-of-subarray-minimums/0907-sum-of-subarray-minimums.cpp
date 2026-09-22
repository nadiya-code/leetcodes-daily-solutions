class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0;
        long long Mod=1e9+7;
        int n=arr.size();
        vector<int>left(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
        vector<int>right(n);
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            sum=(sum+(1LL*arr[i]*(i-left[i])*(right[i]-i))%Mod)%Mod;
        }
        return sum;
    }
};