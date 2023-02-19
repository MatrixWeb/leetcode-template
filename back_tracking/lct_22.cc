// https://leetcode.cn/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int m = n * 2;
        vector<string> ans;
        string path;
        function<void(int, int)> dfs = [&] (int i, int open) {

            if (i == m) {
                ans.push_back(path);
                return;
            }
            // 选左括号
            if (open < n) {
                path.push_back('(');
                dfs(i + 1, open + 1);
                path.pop_back();
            }
            // 可以选右括号
            if (i - open < open) {
                path.push_back(')');
                dfs(i + 1, open);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};