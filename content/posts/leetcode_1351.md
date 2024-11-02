
+++
authors = ["Crafted by Me"]
title = "Leetcode 1351: Count Negative Numbers in a Sorted Matrix"
date = "2020-02-20"
description = "Solution to Leetcode 1351"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0, m = grid.size();
        for(int i = 0; i < m; i++) {
            auto it = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
            if(*grid[i].rbegin() > -1) continue;
            res += it - grid[i].rbegin();
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

