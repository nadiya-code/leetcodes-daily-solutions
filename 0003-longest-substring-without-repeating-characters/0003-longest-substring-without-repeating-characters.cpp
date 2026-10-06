class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>last(256,-1);
        int n=s.size();
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < n; right++) {
            if(last[s[right]]>=left){
                left=last[s[right]]+1;
            }
            last[s[right]]=right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};