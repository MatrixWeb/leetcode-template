// https://leetcode.cn/problems/search-insert-position/

// 直接用库函数写法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return idx;
    }
};