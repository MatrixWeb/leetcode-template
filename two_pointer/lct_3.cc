// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        int ans = 0;
        int left = 0;
        unordered_map<char, int> s_m;
        for (int i = 0; i < n; i++) {
            s_m[s[i]]++;
            while(s_m[s[i]] > 1) {
                s_m[s[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};