class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int minimum=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(j-i+1<l){
                    continue;
                }
                if(j-i+1>r){
                    break;
                }
                if(i==0){
                    if(nums[j]>0)minimum=min(nums[j],minimum);
                }
                else{
                    if(nums[j]-nums[i-1]>0)minimum=min(minimum,nums[j]-nums[i-1]);
                }
            }
        }
        return minimum!=INT_MAX?minimum:-1;
    }
};