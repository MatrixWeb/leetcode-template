// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> m_info = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        if(n == 0) return ans;
        string cur_str;
        // 回溯算法1 枚举每一次选择
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(cur_str);
                return;
            }
            int num = digits[i] - '0';
            for (int j = 0; j < m_info[num].size(); j++) {
                cur_str.push_back(m_info[num][j]);
                dfs(i + 1);
                cur_str.pop_back();
            }
        };
        
        dfs(0);
        return ans;
    }
};