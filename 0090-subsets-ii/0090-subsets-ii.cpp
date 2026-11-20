class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int num=0;num<(1<<n);num++){
            vector<int>array;
            for(int i=0;i<n;i++){
                if(num & (1<<i)){
                    array.push_back(nums[i]);
                }
            }
            if(find(subsets.begin(),subsets.end(),array)==subsets.end()){
                subsets.push_back(array);
            }
        }
        return subsets;
    }
};