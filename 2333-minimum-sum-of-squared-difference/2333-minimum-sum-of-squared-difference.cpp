class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long sum=0;
        int n=nums1.size();
        int k=k1+k2;
        vector<int>diff(100001,0);
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            diff[d]++;
        }
        for(int l=100000;l>0 && k>0 ;l--){
            int operations=min(diff[l],k);
            diff[l]-=operations;
            diff[l-1]+=operations;
            k-=operations;
        }
        for(int j=0;j<=1e5;j++){
            sum+=1LL*diff[j]*j*j;
        }
        return sum;
    }
};