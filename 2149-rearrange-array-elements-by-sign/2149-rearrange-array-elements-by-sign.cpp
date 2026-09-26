class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>array(n);
        int pos=0;
        int neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                array[pos]=nums[i];
                pos+=2;
            }
            else{
                array[neg]=nums[i];
                neg+=2;
            }
        }
        return array;
    }
};