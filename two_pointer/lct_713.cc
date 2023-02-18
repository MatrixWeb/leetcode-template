// https://leetcode.cn/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int left = 0;
        long long prod = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            while(prod >= k) {
                prod /= nums[left];
                left ++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};