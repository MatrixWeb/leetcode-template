// https://leetcode.cn/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        // 遍历子集搜索树
        function<void(int, int)> dfs = [&] (int i, int t) {
            int d = k - path.size();
            // 剪枝
            if (t < 0 || t > (i * 2 - d + 1) * d / 2) {
                return;
            }
            if (path.size() == k) {
                // 进到这里t必然等于0
                ans.push_back(path);
                return;
            }
            for (int j = i; j >= d; j--) {
                path.push_back(j);
                dfs(j - 1, t - j);
                path.pop_back();
            }
        };
        dfs(9, n);
        return ans;
    }
};