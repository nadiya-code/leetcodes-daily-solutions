class Solution {
public:
    bool canSort(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = INT_MIN;

        for (int start = 0; start < n; start += k) {
            int descents = 0;
            int mn = INT_MAX;
            int mx = INT_MIN;

            for (int i = start; i < start + k; i++) {
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);

                if (i > start && nums[i - 1] > nums[i]) {
                    descents++;
                }
            }

            if (k > 1 && nums[start + k - 1] > nums[start]) {
                descents++;
            }

            if (descents > 1) {
                return false;
            }

            if (prevMax > mn) {
                return false;
            }

            prevMax = mx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && canSort(nums, k)) {
                ans += k;
            }
        }

        return ans;
    }
};