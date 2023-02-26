// https://leetcode.cn/problems/house-robber/
// dp，记忆化搜索
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        function<int(int)> dfs = [&] (int i) -> int {
            if (i < 0) return 0;
            if (cache[i] != -1) {
                return cache[i];
            }
            return cache[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]);
        };
        return dfs(n - 1);
    }
};

// dp，直接推
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 2, 0);
        for (int i = 0; i < n; i++) {
            f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        }
        return f[n + 1];
    }
};

// 空间优化成O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0, f1 = 0;
        for (auto e : nums) {
            int new_f = max(f1, f0 + e);
            f0 = f1;
            f1 = new_f;
        }
        return max(f0, f1);
    }
};