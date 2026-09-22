class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long summin=0;
        long long summax=0;
        int n=nums.size();
        vector<pair<int,int>>left(n);
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
                left[i].first=-1;
            }
            else{
                left[i].first=stmin.top();
            }
            if(stmax.empty()){
                left[i].second=-1;
            }
            else{
                left[i].second=stmax.top();
            }
            stmin.push(i);
            stmax.push(i);
        }
        vector<pair<int,int>>right(n);
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
                right[i].first=n;
            }
            else{
                right[i].first=stmin.top();
            }
            if(stmax.empty()){
                right[i].second=n;
            }
            else{
                right[i].second=stmax.top();
            }
            stmin.push(i);
            stmax.push(i);
        }
        for(int i=0;i<n;i++){
            summin+=(1LL*nums[i]*(i-left[i].first)*(right[i].first-i));
            summax+=(1LL*nums[i]*(i-left[i].second)*(right[i].second-i));
        }
        return summax-summin;
    }
};