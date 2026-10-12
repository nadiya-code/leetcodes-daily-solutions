class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        // cnt[b] = number of elements having bit b set
        vector<int> cnt(31, 0);

        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                if (x & (1 << b)) {
                    cnt[b]++;
                }
            }
        }

        long long ans = 0;

        for (int t = 0; t < k; t++) {
            long long x = 0;

            // Build the largest possible number
            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};