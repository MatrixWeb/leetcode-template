// https://leetcode.cn/problems/trapping-rain-water/

// 每个格子当木桶，能接的水是左右挡板最小值 - 当前格子高度
// 双指针算，如果前缀最大值 < 后缀最大值， 说明当前左格子挡板最小值一定是前缀最大值。直接算左挡板格子雨水量
// 反之亦然 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int pre_max = 0, sub_max = 0;
        int left = 0, right = n - 1;
        int ans = 0;
        while(left < right) {
            pre_max = max(height[left], pre_max);
            sub_max = max(height[right], sub_max);
            if (pre_max < sub_max) {
                ans += pre_max - height[left];
                left ++;
            } else {
                ans += sub_max - height[right];
                right --;
            }
        }
        return ans;
    }
};