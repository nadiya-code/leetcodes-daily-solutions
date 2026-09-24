class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<10){
                if(nums[i]==i){
                    return i;
                }
            }
            else{
                int num=0;
                while(nums[i]>0){
                    num+=nums[i]%10;
                    nums[i]/=10;
                }
                if(num==i){
                    return i;
                }
            }
        }
        return -1;
    }
};