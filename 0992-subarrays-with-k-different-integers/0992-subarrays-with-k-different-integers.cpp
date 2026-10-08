class Solution {
public:
    int atMost(vector<int>& nums, int k){
        if(k<=0){
            return 0;
        }
        int left=0;
        int count=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            count+=i-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};