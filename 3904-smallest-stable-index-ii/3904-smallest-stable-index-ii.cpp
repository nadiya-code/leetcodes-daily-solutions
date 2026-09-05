class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minimum(n);
        int mini=INT_MAX;
        int maxi=nums[0];
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            minimum[i]=mini;
        }
        int stableValue=maxi-minimum[0];
        if(stableValue<=k){
            return 0;
        }
        for(int i=1;i<n;i++){
            maxi=max(maxi,nums[i]);
            stableValue=maxi-minimum[i];
            if(stableValue<=k){
                return i;
            }
        }
        return -1;
    }
};