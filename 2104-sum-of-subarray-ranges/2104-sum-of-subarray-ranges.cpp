class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long summin=0;
        long long summax=0;
        int n=nums.size();
        vector<int>leftmin(n);
        vector<int>leftmax(n);
        stack<int>stmax;
        stack<int>stmin;
        for(int i=0;i<n;i++){
            while(!stmin.empty() && nums[stmin.top()]>nums[i]){
                stmin.pop();
            }
            while(!stmax.empty() && nums[stmax.top()]<nums[i]){
                stmax.pop();
            }
            if(stmin.empty()){
                leftmin[i]=-1;
            }
            else{
                leftmin[i]=stmin.top();
            }
            if(stmax.empty()){
                leftmax[i]=-1;
            }
            else{
                leftmax[i]=stmax.top();
            }
            stmin.push(i);
            stmax.push(i);
        }
        vector<int>rightmin(n);
        vector<int>rightmax(n);
        while(!stmin.empty()){
            stmin.pop();
        }
        while(!stmax.empty()){
            stmax.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!stmin.empty() && nums[stmin.top()]>=nums[i]){
                stmin.pop();
            }
            while(!stmax.empty() && nums[stmax.top()]<=nums[i]){
                stmax.pop();
            }
            if(stmin.empty()){
                rightmin[i]=n;
            }
            else{
                rightmin[i]=stmin.top();
            }
            if(stmax.empty()){
                rightmax[i]=n;
            }
            else{
                rightmax[i]=stmax.top();
            }
            stmin.push(i);
            stmax.push(i);
        }
        for(int i=0;i<n;i++){
            summin+=(1LL*nums[i]*(i-leftmin[i])*(rightmin[i]-i));
            summax+=(1LL*nums[i]*(i-leftmax[i])*(rightmax[i]-i));
        }
        return summax-summin;
    }
};