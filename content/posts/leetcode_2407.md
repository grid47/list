
+++
authors = ["Crafted by Me"]
title = "Leetcode 2407: Longest Increasing Subsequence II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2407: Longest Increasing Subsequence II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Dynamic Programming","Binary Indexed Tree","Segment Tree","Queue","Monotonic Queue"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-increasing-subsequence-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class MxSegT {
    public:
    int n;
    vector<int> tree;
    MxSegT(int n) {
        this-> n = n;
        int k = (int)(ceil(log2(n)));
        int sz = 2 * (int)pow(2, k) - 1;
        tree.resize(sz, 0);
    }
    
    int mx_val() {
        return tree[0];
    }
    
    void update(int val, int i) { write(0, val, i, 0, n - 1); }
    
    void write(int root, int val, int pos, int wL, int wR) {
        if(pos < wL || pos > wR) {
            return;
        }
        if(wL == wR) {
            tree[root] = max(val, tree[root]);
            return;
        }
        int mid = (wL + wR) / 2;
        write(2 * root + 1, val, pos, wL, mid);
        write(2 * root + 2, val, pos, mid + 1, wR);
        tree[root] = max(tree[2 * root + 1], tree[2 * root + 2]);
    }
    
    int query(int l, int r) { return read(0, l, r, 0, n - 1); }
    
    int read(int root, int l, int r, int wL, int wR) {
        if(l <= wL && r >= wR) return tree[root];
        if(wR < l || wL > r) {
            return INT_MIN;
        }
        int mid = (wL + wR) / 2;
        return max( read(2 * root + 1, l, r, wL,     mid),
                    read(2 * root + 2, l, r, mid + 1, wR));
    }

};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        MxSegT tree = MxSegT(1e5 + 1);
        int n = nums.size();
        for(int x: nums) {
            int low = max(0, x - k);
            int cur = 1 + tree.query(low, x - 1);
            tree.update(cur, x);
        }
        return tree.mx_val();
    }
};
{{< /highlight >}}


---
{{< youtube 8Xf__4h4s18 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2408: Design SQL](https://grid47.xyz/posts/leetcode_2408) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
