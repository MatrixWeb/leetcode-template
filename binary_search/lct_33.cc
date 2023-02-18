// https://leetcode.cn/problems/search-in-rotated-sorted-array/submissions/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 2;
        int end = nums[n - 1];
        // lambda 节省传参数
        auto is_blue = [&](int i) {
            if (nums[i] > end) {
                return target > end && nums[i] >= target;
            } else {
                return target > end || nums[i] >= target;
            }
        };
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (is_blue(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(n == left || nums[left] != target) {
            return -1;
        }
        return left;
    }
};