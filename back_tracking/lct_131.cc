// https://leetcode.cn/problems/palindrome-partitioning/

// 回溯算法2 ： 枚举当前答案的每一种可能，再往后递归
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<string> path;
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                string tmp_str = s.substr(i, j + 1 - i);
                string tmp_str2 = tmp_str;
                reverse(tmp_str.begin(), tmp_str.end());
                if (tmp_str == tmp_str2) {
                    path.push_back(tmp_str);
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};