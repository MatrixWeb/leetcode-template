// https://leetcode.cn/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       int n = nums.size();
       // 标记那些没用过
       vector<int> path(n), is_use(n,false);
       function<void(int)> dfs = [&] (int i) {
           if (i == n) {
               ans.emplace_back(path);
               return;
           }
           for (int j = 0; j < n; j++) {
               if (!is_use[j]) {
                   is_use[j] = true;
                   path[i] = nums[j];
                   dfs(i + 1);
                   is_use[j] = false; 
               }
           }
       };
       dfs(0);
       return ans;
    }
};