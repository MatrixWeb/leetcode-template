// https://leetcode.cn/problems/find-peak-element/submissions/

// 模版详见lct_34.cc
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      // 闭区间[left, right]， 二分查找>= 山顶位置
        int left = 0, right = nums.size() - 2;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
              // 说明左边[0, mid]一定不符合条件，left指向待定区间
                left = mid + 1;
            } else {
              // 说明[mid, n]一定在山顶或山顶右侧
                right = mid - 1;
            }
        }
        return left;
    }
};