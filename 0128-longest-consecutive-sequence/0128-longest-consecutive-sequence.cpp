class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int length=0;
        for(int x :s){
            if(s.find(x-1)==s.end()){
                int l=1;
                int curr=x;
                while(s.find(curr+1)!=s.end()){
                    l++;
                    curr++;
                }
                length=max(length,l);
            }
        }
        return length;
    }
};