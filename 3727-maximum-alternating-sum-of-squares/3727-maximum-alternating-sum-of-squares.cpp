class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            return abs(1LL*a)<abs(1LL*b);
        });
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n/2;i++){
            sum-=nums[i]*nums[i];
        }
        for(int i=n/2;i<n;i++){
            sum+=nums[i]*nums[i];
        }
        return sum;
    }
};