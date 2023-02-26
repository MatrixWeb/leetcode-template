
// https://leetcode.cn/problems/count-special-integers/
// 数位dp模版
// mask 当前数字在不在mask里面
// is_limit 当前填充是否收到约束，为真只能填到s[i], 否则可以到9
// is_num 前面是否已经填过数字，若为真此次可以跳过
// dp_digital_template
class Solution {
public:
    int countSpecialNumbers(int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool, bool)> dfs = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m) return is_num;
            // 记忆化搜索
            if (!is_limit && is_num && dp[i][mask] >= 0) {
                return dp[i][mask];
            }
            int res = 0;
            // 是否可以跳过
            if (!is_num) res = dfs(i + 1, mask, false, false);
            int up = is_limit ? s[i] - '0' : 9;
            for (int d = 1 - is_num; d <= up; d++) {
                if ((mask >> d & 1) == 0) {
                    res += dfs(i + 1, mask | (1 << d), is_limit && d == up, true);
                }
            }
            // 记忆化搜索
            if (!is_limit && is_num) dp[i][mask] = res;
            return res;
        };
        return dfs(0, 0, true, false);
    }
};