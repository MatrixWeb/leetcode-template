// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// 二分查找
class Solution {
public:
    // 闭区间二分
    // >= target的第一个数
    // > x 转化为 >= x+1
    // < x 转化为 idx(>= x) - 1
    // <= x 转化为 idx(>x) - 1
    int get_lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        // [left, right]
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                // mid指向不符合条件，left 移动指向待选区间
                left = mid + 1;
            } else {
                // right 指向待选区间
                right = mid - 1;
            }
        }
        // right + 1 永远指向答案， 最后时刻right + 1 = left
        // 当left == n 时，找不到>= target的数，数组的元素永远小于target
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // 找到>= target的左起始点
        int left_idx = get_lower_bound(nums, target);
        if (left_idx == n || nums[left_idx] != target) {
            return {-1, -1};
        }
        // 找到>= target + 1的左起始点，然后 - 1即为<= target的右结束点
        int right_idx = get_lower_bound(nums, target + 1) - 1;
        return {left_idx, right_idx};
    }
};