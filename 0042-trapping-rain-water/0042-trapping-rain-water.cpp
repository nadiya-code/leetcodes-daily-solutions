class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>SuffixMax(height.begin(),height.end());
        for(int i=n-2;i>=0;i--){
            SuffixMax[i]=max(SuffixMax[i+1],SuffixMax[i]);
        }
        int total=0;
        int prefixMax=height[0];
        for(int i=0;i<n;i++){
            prefixMax=max(prefixMax,height[i]);
            if(prefixMax>height[i] && SuffixMax[i]>height[i]){
                total+=min(prefixMax,SuffixMax[i])-height[i];
            }
        }
        return total;
    }
};