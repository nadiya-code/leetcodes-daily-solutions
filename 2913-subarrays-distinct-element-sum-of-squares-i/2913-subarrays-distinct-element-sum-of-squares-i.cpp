class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                sum+=1LL*mp.size()*mp.size();
            }
        }
        return sum;
    }
};