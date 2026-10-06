class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int length=0;
        int left=0;
        int zeros=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeros++;
            }
            while(zeros>k && left<n){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
            length=max(length,i-left+1);
        }
        return length;
    }
};