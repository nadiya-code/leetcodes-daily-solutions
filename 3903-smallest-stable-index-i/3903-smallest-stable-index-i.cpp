class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maximum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
            int minimum=INT_MAX;
            for(int j=i;j<n;j++){
                minimum=min(minimum,nums[j]);
            }
            if(maximum-minimum<=k){
                return i;
            }
        }
        return -1;
    }
};