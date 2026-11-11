class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long costA=(long long)need1*cost1+(long long)need2*cost2;
        long long costB=(long long)costBoth*max(need1,need2);
        int both=min(need1,need2);
        long long costC=1LL*costBoth*both+1LL*(need1-both)*cost1+1LL*cost2*(need2-both);
        return min({costA,costB,costC});
    }
};