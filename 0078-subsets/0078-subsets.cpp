class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>p;
        int n=nums.size();
        for(int num=0;num<pow(2,n);num++){
            vector<int>s;
            for(int i=0;i<n;i++){
                if(num & (1<<i)){
                    s.push_back(nums[i]);
                }
            }
            p.push_back(s);
        }
        return p;
    }
};