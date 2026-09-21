class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        int right=n-1;
        int left=0;
        int leftMax=0;
        int rightMax=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftMax){
                    leftMax=height[left];
                }
                total+=leftMax-height[left++];
            }
            else{
                if(height[right]>=rightMax){
                    rightMax=height[right];
                }
                total+=rightMax-height[right--];
            }
        }
        return total;
    }
};