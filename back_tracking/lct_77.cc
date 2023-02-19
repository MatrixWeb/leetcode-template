// https://leetcode.cn/problems/combinations/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        // 遍历子集搜索树
        function<void(int)> dfs = [&] (int i) {
            if (path.size() == k) {
                ans.push_back(path);
                return;
            }
            // 还剩d个可填充
            int d = k - path.size();
            for (int j = i; j > d - 1; j--) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }
        };
        dfs(n);
        return ans;
    }
};