class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // At most one character can have odd frequency
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Remove the middle character
        if (n % 2)
            cnt[mid - 'a']--;

        /*
            cnt now contains the characters available
            for both left and right halves.

            If we put 'a' on the left,
            we need TWO 'a's from cnt.
        */

        // Try making left half exactly target's left half
        for (int i = 0; i < n / 2; i++) {
            int x = target[i] - 'a';

            cnt[x] -= 2;
        }

        // Check whether target's left half is possible
        bool possible = true;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] < 0) {
                possible = false;
                break;
            }
        }

        /*
            If target's left half is possible,
            construct the palindrome having exactly
            that left half.

            It may already be greater than target because
            the right half differs.
        */
        if (possible) {
            string left = target.substr(0, n / 2);

            string right = left;
            reverse(right.begin(), right.end());

            string candidate = left;

            if (n % 2)
                candidate += mid;

            candidate += right;

            if (candidate > target)
                return candidate;
        }

        /*
            Now we need to make the LEFT half greater.

            Start from the rightmost position and move left.

            Example:

            target left = "abc"

                       ↑
                       Try increasing c

            If impossible:

                    ↑
            Try increasing b
        */

        for (int i = n / 2 - 1; i >= 0; i--) {

            // Restore target[i]'s TWO copies
            int cur = target[i] - 'a';
            cnt[cur] += 2;

            // We need target[0 ... i-1] to remain unchanged.
            // Those characters must still be available.

            bool valid = true;

            for (int j = 0; j < 26; j++) {
                if (cnt[j] < 0) {
                    valid = false;
                    break;
                }
            }

            if (!valid)
                continue;

            // Try the smallest character > target[i]
            for (int c = cur + 1; c < 26; c++) {

                if (cnt[c] < 2)
                    continue;

                // Prefix stays equal to target
                string left = target.substr(0, i);

                // Increase position i
                left += char('a' + c);

                cnt[c] -= 2;

                // Fill remaining positions with smallest chars
                for (int pos = i + 1; pos < n / 2; pos++) {

                    for (int x = 0; x < 26; x++) {

                        if (cnt[x] >= 2) {
                            left += char('a' + x);
                            cnt[x] -= 2;
                            break;
                        }
                    }
                }

                // Build palindrome
                string right = left;
                reverse(right.begin(), right.end());

                string ans = left;

                if (n % 2)
                    ans += mid;

                ans += right;

                return ans;
            }
        }

        return "";
    }
};