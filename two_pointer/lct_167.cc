// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
// two_pointer_template2
// 相向双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if (nums[left] + nums[right] > target) {
                right --;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                break;
            }
        }
        return {left + 1, right + 1};
    }
};