
+++
authors = ["Crafted by Me"]
title = "Leetcode 1964: Find the Longest Valid Obstacle Course at Each Position"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1964: Find the Longest Valid Obstacle Course at Each Position in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Binary Indexed Tree"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();
        vector<int> ans(n, 1), tmp;
        for(int i = 0; i < n; i++) {
            if(tmp.empty() || tmp.back() <= obs[i]) {
                tmp.push_back(obs[i]);
                ans[i] = tmp.size();
            } else {
                int idx = upper_bound(tmp.begin(), tmp.end(), obs[i]) - tmp.begin();
                tmp[idx] = obs[i];
                ans[i] = idx + 1;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1964.md" >}}
---
{{< youtube Xq9VT7p0lic >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1965: Employees With Missing Information](https://grid47.xyz/posts/leetcode_1965) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
