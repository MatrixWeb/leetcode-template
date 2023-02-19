// https://leetcode.cn/problems/find-positive-integer-solution-for-a-given-equation/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int y = 1000;
        int x = 1;
        // 相向双指针
        while(x <= 1000 && y) {
            int c_r = customfunction.f(x, y);
            if (c_r < z) {
                x++;
            } else if (c_r > z) {
                y--;
            } else {
                ans.push_back({x, y});
                x++, y--;
            }
        }
        return ans;
    }
};