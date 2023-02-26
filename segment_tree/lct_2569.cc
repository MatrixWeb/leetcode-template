// https://leetcode.cn/problems/handling-sum-queries-after-update/
// segment_template1
class Solution {
    static constexpr int MX = 4e5 + 1;
    // 维护的数，lazy模式
    int cnt1[MX];
    bool flip[MX];

    void push_up(int o) {
        cnt1[o] = cnt1[o * 2] + cnt1[o * 2 + 1];
    }

    void do_(int o, int l, int r) {
        cnt1[o] = r - l + 1 - cnt1[o];
        flip[o] = !flip[o];
    }
    // 建立线段树
    void build(vector<int>& a, int o, int l, int r) {
        if (l == r) {
            cnt1[o] = a[l - 1];
            return;
        }
        int m = (l + r) / 2;
        build(a, o * 2, l, m);
        build(a, o * 2 + 1, m + 1, r);
        push_up(o);
    }
    // 反转[L, R]
    void update(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            do_(o, l, r);
            return;
        }
        int m = (l + r) / 2;
        if (flip[o]) {
            do_(o * 2, l, m);
            do_(o * 2 + 1, m + 1, r);
            flip[o] = false;
        }
        if (m >= L) update(o * 2, l, m, L, R);
        if (m < R) update(o * 2 + 1, m + 1, r, L, R);
        push_up(o);
    }

public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        build(nums1, 1, 1, n);
        vector<long long> ans;
        long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        for (auto &q : queries) {
            if (q[0] == 1) update(1, 1, n, q[1] + 1, q[2] + 1);
            else if (q[0] == 2) sum += 1LL * q[1] *cnt1[1];
            else ans.push_back(sum);
        }
        return ans;
    }
};