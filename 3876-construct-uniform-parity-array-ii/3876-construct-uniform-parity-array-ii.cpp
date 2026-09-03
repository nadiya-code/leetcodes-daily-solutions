class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd=INT_MAX;
        int mineven=INT_MAX;
        for(int &num:nums1){
            if(num%2==0 && mineven>num){
                mineven=num;
            }
            else if(num%2!=0 && minodd>num){
                minodd=num;
            }
        }
        if(minodd==INT_MAX||mineven==INT_MAX){
            return true;
        }
        return minodd<mineven;
    }
};