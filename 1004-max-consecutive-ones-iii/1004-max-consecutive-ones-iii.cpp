class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=k){
            return n;
        }
        int length=0;
        int left=0;
        deque<int>dq;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                dq.push_back(i);
            }
            if(dq.size()>k){
                left=dq.front()+1;
                dq.pop_front();
            }
            length=max(length,i-left+1);
        }
        return length;
    }
};