// https://leetcode.cn/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            int x = nums[i];
            // 跳过重复数字
            if (i > 0 && x == nums[i - 1]) continue;
            if (x + nums[i + 1] + nums[i + 2] > 0) break;
            if (x + nums[n - 1] + nums[n - 2] < 0) continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                if (x + nums[left] + nums[right] < 0) {
                    left ++;
                } else if (x + nums[left] + nums[right] > 0) {
                    right --;
                } else {
                    ans.push_back({x, nums[left], nums[right]});
                    left++;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left ++;
                    }
                    right --;
                    while(left < right && nums[right] == nums[right+1]) {
                        right --;
                    }
                }
            }
        }
        return ans;
    }
};