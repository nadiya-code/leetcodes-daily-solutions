class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlength=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                sum--;
            }
            else{
                sum++;
            }
            if(mp.find(sum)!=mp.end()){
                maxlength=max(maxlength,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return maxlength;
    }
};