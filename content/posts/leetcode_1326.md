
+++
authors = ["Crafted by Me"]
title = "Leetcode 1326: Minimum Number of Taps to Open to Water a Garden"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1326: Minimum Number of Taps to Open to Water a Garden in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int n;
    vector<int> memo;
    vector<vector<int>> win;
    
    int bs(int idx, int num) {
        int l = idx, r = win.size() - 1;
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(win[mid][0] <= num) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
    
    int dp(int idx) {

        if(idx == win.size()) return INT_MAX;
        if(win[idx][1] >= n) return 1;
        if(win[idx][1] == win[idx][0]) return INT_MAX;        
        if (memo[idx] != -1) return memo[idx];
        
        int ans = INT_MAX;
        int nxt = bs(idx + 1, win[idx][1]);
        // cout << idx << nxt << " ";
        if(nxt != -1) {
            for(int i = idx + 1; i <= nxt; i++) {
                int ret = dp(i);
                ans = min(ans, ret == INT_MAX? ret: ret + 1);
            }
        }

        return memo[idx] = ans;
    }
    
    int minTaps(int n, vector<int>& r) {
        this->n = n;
        for(int i = 0; i < r.size(); i++)
        win.push_back({i - r[i], i + r[i]});
        sort(win.begin(), win.end());
        memo.resize(r.size() + 1, -1);
        int ret = INT_MAX;
        for(int i = 0; i < r.size() && win[i][0] <= 0; i++)
            ret = min(dp(i), ret);
        return ret == INT_MAX? -1: ret;
    }
    // [1,2,1,0,2,1,0,1]
    // [0,1,2,3,4,5,6,7]
    // {{-1, 1}, {-1, 3}, {1, 3}, {2, 6}, {3, 3}, {4, 6}, {6, 6}, {6, 8}}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1326.md" >}}
---
{{< youtube XFvX7uMo7uk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1327: List the Products Ordered in a Period](https://grid47.xyz/posts/leetcode_1327) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

