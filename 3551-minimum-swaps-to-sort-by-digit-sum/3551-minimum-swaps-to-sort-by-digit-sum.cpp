class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>> arr;
        for(int i=0;i<n;i++){
            int sum=0;
            int c=nums[i];
            while(c){
                sum+=c%10;
                c/=10;
            }
            arr.push_back({sum,nums[i]});
        }
        sort(arr.begin(),arr.end());
        int swapped=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            while(nums[i]!=arr[i].second){
                int j=mp[arr[i].second];
                swap(nums[i],nums[j]);
                mp[nums[j]]=j;
                mp[nums[i]]=i;
                swapped++;
            }
        }
        return swapped;
    }
};