class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sumSq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sumSq =
            (tree[node].sumSq
             + 2LL * val * tree[node].sum
             + val * val % MOD * len) % MOD;

        tree[node].sum =
            (tree[node].sum + val * len) % MOD;

        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum
             + tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSq =
            (tree[node * 2].sumSq
             + tree[node * 2 + 1].sumSq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);

        vector<int> lastSeen(100001, -1);

        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int prev = lastSeen[nums[r]];

            update(1, 0, n - 1, prev + 1, r);

            lastSeen[nums[r]] = r;

            ans = (ans + tree[1].sumSq) % MOD;
        }

        return ans;
    }
};