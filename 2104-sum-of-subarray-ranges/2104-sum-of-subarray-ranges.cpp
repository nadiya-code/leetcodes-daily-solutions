class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int minimum=nums[i];
            int maximum=nums[i];
            for(int j=i+1;j<n;j++){
                minimum=min(minimum,nums[j]);
                maximum=max(maximum,nums[j]);
                sum+=1LL*(maximum-minimum);
            }
        }
        return sum;
    }
};