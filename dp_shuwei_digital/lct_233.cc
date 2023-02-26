// https://leetcode.cn/problems/number-of-digit-one/
class Solution {
public:
    int countDigitOne(int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m][m];
        memset(dp, -1, sizeof(dp));
        // 前导0对统计无影响
        // 返回表示从左往右到了第i位， 前面已经出现了cnt1个1的情况下，最终会得到1的个数
        function<int(int, int, bool)> dfs = [&](int i, int cnt1, bool is_limit) -> int {
            if (i == m) return cnt1;
            // 记忆化搜索
            if (!is_limit && dp[i][cnt1] >= 0) {
                return dp[i][cnt1];
            }
            int res = 0;
            // 是否可以跳过
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 0; d <= up; d++) {
                res += dfs(i + 1, cnt1 + (d == 1), is_limit && d == up);
            }
            // 记忆化搜索
            if (!is_limit) dp[i][cnt1] = res;
            return res;
        };
        return dfs(0, 0, true);
    }
};