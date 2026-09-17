class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> expected(heights.begin(),heights.end());
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(expected[j]>expected[j+1]){
                    swap(expected[j],expected[j+1]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(heights[i]!=expected[i]){
                count++;
            }
        }
        return count;
    }
};