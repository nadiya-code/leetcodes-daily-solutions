class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minimum(n);
        minimum[n-1]=nums[n-1];
        int maxi=INT_MIN;
        for(int i=n-2;i>=0;i--){
            minimum[i]=min(minimum[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-minimum[i]<=k){
                return i;
            }
        }
        return -1;
    }
};