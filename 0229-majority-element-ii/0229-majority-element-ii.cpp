class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>array;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int &num :nums){
            mp[num]++;
        }
        for(auto &m:mp){
            if(m.second>n/3){
                array.push_back(m.first);
            }
        }
        return array;
    }
};