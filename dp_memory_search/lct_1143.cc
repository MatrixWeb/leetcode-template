// https://leetcode.cn/problems/longest-common-subsequence/

// 二个子串 的dp， 也可以用记忆化搜索 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                } else {
                    f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
                }
            }
        return f[n][m];
    }
};