class Solution {
public:
    int atMost(vector<int>&nums ,int k){
        if(k<0){
            return 0;
        }
        int odd=0;
        int count=0;
        int left=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                odd++;
            }
            while(odd>k){
                if(nums[left]%2==1){
                    odd--;
                }
                left++;
            }
            count+=i-left+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};