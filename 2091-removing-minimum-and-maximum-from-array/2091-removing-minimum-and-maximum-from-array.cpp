class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minimum=nums[0];
        int maximum=nums[0];
        int maxindex=0;
        int minindex=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(minimum>nums[i]){
                minimum=nums[i];
                minindex=i;
            }
            if(maximum<nums[i]){
                maxindex=i;
                maximum=nums[i];
            }
        }
        int left=max(minindex+1,maxindex+1);
        int right=max(n-minindex,n-maxindex);
        int both=min(minindex,maxindex)+1+n-max(minindex,maxindex);
        return min({left,right,both});
    }
};