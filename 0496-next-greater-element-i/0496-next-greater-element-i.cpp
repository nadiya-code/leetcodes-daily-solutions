class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> array;
        int id;
        for(int i=0;i<nums1.size();i++){
            auto it=find(nums2.begin(),nums2.end(),nums1[i]);
            id=it-nums2.begin();
            int next=-1;
            for(int j=id+1;j<nums2.size();j++){
                if(nums2[j]>nums1[i]){
                    next=nums2[j];
                    break;
                }
            }
            array.push_back(next);
        }
        return array;
    }
};