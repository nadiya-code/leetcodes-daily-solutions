class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd=INT_MAX;
        int mineven=INT_MAX;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0 && mineven>nums1[i]){
                mineven=nums1[i];
            }
            else if(nums1[i]%2!=0 && minodd>nums1[i]){
                minodd=nums1[i];
            }
        }
        if(minodd==INT_MAX||mineven==INT_MAX){
            return true;
        }
        return minodd<mineven;
    }
};