// https://leetcode.cn/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int f[n+1][m+1];
        for (int i = 0; i <= m; i ++) f[0][i] = i;
        for (int i = 0; i < n; i++) {
            f[i + 1][0] = i + 1;
            for (int j = 0; j < m; j++) {
                if (word1[i] == word2[j]) {
                    f[i + 1][j + 1] = f[i][j];
                } else {
                    f[i + 1][j + 1] = min (min(f[i + 1][j], f[i][j]), f[i][j + 1]) + 1;
                }
            }
        }
        return f[n][m];
    }
};