class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd=INT_MAX;
        int mineven=INT_MAX;
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0 && mineven==INT_MAX){
                mineven=nums1[i];
            }
            else if(nums1[i]%2!=0 && minodd==INT_MAX){
                minodd=nums1[i];
            }
        }
        if(minodd==INT_MAX||mineven==INT_MAX){
            return true;
        }
        return minodd<mineven;
    }
};