
// https://leetcode.cn/problems/coin-change/
// 完全背包，价值为1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int f[amount + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            // 完全背包正序遍历，因为当前结果由当前行子问题求解
            for (int j = coins[i]; j <= amount; j++) {
                f[j] = min(f[j], f[j - coins[i]] + 1);
            }
        }
        int ans = f[amount];
        return ans < 0x3f3f3f3f ? ans : -1;
    }
};