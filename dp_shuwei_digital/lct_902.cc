// https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m];
        memset(dp, -1, sizeof(dp));
        function<int(int, bool, bool)> dfs = [&](int i, bool is_limit, bool is_num) -> int {
            if (i == m) return is_num;
            // 记忆化搜索
            if (!is_limit && is_num && dp[i] >= 0) {
                return dp[i];
            }
            int res = 0;
            // 是否可以跳过
            if (!is_num) res = dfs(i + 1, false, false);
            int up = is_limit ? s[i] - '0' : 9;
            for (auto d : digits) {
                int cur = d[0] - '0';
                if (cur <= up) {
                    res += dfs(i + 1, is_limit && cur == up, true);
                }
            }
            // 记忆化搜索
            if (!is_limit && is_num) dp[i] = res;
            return res;
        };
        return dfs(0, true, false);
    }
};