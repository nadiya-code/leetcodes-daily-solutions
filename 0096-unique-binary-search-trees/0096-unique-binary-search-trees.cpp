class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int nodes=2;nodes<=n;nodes++){
            for(int roots=1;roots<=nodes;roots++){
                int left=roots-1;
                int right=nodes-roots;
                dp[nodes]+=dp[left]*dp[right];
            }
        }
        return dp[n];
    }
};