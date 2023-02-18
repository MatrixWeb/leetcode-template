// https://leetcode.cn/problems/minimum-size-subarray-sum/
// two_pointer_template1
// 同向双指针
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        int ans = n + 1;
        // 每次取right 加进来判断是否符合
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            // 移动左指针
            while(sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if (sum >= target) {
                ans = min(ans, right - left + 1);
            }
        }
        return ans <= n ? ans : 0;
    }
};