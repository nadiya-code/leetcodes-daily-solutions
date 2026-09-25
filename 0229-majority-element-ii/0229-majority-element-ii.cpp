class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>array;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i+n/3<n;i++){
            if(nums[i+n/3]==nums[i]){
                array.push_back(nums[i]);
                int prev=nums[i];
                i+=n/3;
                while(i<n && nums[i]==prev){
                    i++;
                }
                i--;
            }
        }
        return array;
    }
};