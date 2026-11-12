class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=1;
            while(i+1<n && nums[i]<nums[i+1]){
                l++;
                i++;
            }
            length=max(l,length);
        }
        for(int i=0;i<n;i++){
            int l=1;
            while(i+1<n && nums[i]>nums[i+1]){
                l++;
                i++;
            }
            length=max(l,length);
        }
        return length;
    }
};