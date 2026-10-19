class Solution {
private:
    int lower_bound(vector<int>& nums, int target){
        int left=0;
        int right=nums.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target){
                right=mid-1;
                ans=mid;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
    int upper_bound(vector<int>& nums, int target){
        int left=0;
        int right=nums.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<=target){
                left=mid+1;
                ans=mid;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> indics;
        int start=lower_bound(nums,target);
        int end=upper_bound(nums,target);
        if(start!=-1&&end!=-1){
            for(int i=start;i<=end;i++){
            indics.push_back(i);
            }
        }
        return indics;
    }
};