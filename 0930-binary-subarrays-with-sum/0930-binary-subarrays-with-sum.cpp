class Solution {
public:
    int atMost(vector<int> &nums ,int goal){
        if(goal<0){
            return 0;
        }
        int  sum=0;
        int left=0;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=i-left+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};