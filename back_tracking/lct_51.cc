// https://leetcode.cn/problems/n-queens/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> col(n);
        vector<bool> is_use(n, false);
        int m = 2 * n - 1;
        // 对角线相等条件，不能出现r+c 一样，不能出现r-c一样
        vector<bool> diag1(m, false), diag2(m, false);
        function<void(int)> dfs = [&] (int r) {
            if (r == n) {
                vector<string> path(n);
                for (int i = 0; i < n; i++) {
                    path[i] = string(col[i], '.') + 'Q' + string(n - 1 - col[i], '.');
                }
                ans.push_back(path);
                return;
            }
            for (int c = 0; c < n; c++) {
              // + n - 1防止数组下标越界
                if (!is_use[c] && !diag1[r+c] && !diag2[r - c + n - 1]) {
                    is_use[c] = diag1[r+c] = diag2[r - c + n - 1] = true;
                    col[r] = c;
                    dfs(r + 1);
                    is_use[c] = diag1[r+c] = diag2[r - c + n - 1] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};