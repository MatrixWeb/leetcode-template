// https://leetcode.cn/problems/my-calendar-iii/

class MyCalendarThree {
public:
    // first是维护的数， second是懒加载标记
    // 动态开点
    unordered_map<int, pair<int, int>> tree;

    MyCalendarThree() {

    }
    
    void update(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return;
        } 
        if (start <= l && r <= end) {
            tree[idx].first++;
            tree[idx].second++;
        } else {
            int mid = (l + r) >> 1;
            update(start, end, l, mid, 2 * idx);
            update(start, end, mid + 1, r, 2 * idx + 1);
            // 类似于push_down
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }

    int book(int start, int end) {            
        update(start, end - 1, 0, 1e9, 1);
        return tree[1].first;
    }
};