// https://leetcode.cn/problems/target-sum/
// 0-1背包算出 容量总和恰好等于p的方案数
// p = (s + t) / 2;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int p = accumulate(nums.begin(), nums.end(), 0) + target;
        if (p < 0 || p % 2) {
            return 0;
        }
        p = p / 2;
        int n = nums.size();
        vector<int> f(p + 1);
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            // 0-1背包要逆序算，因为当前结果由上一行数组得到
            for (int j = p; j >= nums[i]; j--) {
                f[j] = f[j] + f[j - nums[i]];
            }
        }
        return f[p];
    }
};