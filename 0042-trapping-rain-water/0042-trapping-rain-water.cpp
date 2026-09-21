class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefixMax(height.begin(),height.end());
        vector<int>SuffixMax(height.begin(),height.end());
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],prefixMax[i]);
        }
        for(int i=n-2;i>=0;i--){
            SuffixMax[i]=max(SuffixMax[i+1],SuffixMax[i]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            if(prefixMax[i]>height[i] && SuffixMax[i]>height[i]){
                total+=min(prefixMax[i],SuffixMax[i])-height[i];
            }
        }
        return total;
    }
};