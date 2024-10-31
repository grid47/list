
+++
authors = ["Crafted by Me"]
title = "Leetcode 1351: Count Negative Numbers in a Sorted Matrix"
date = "2021-02-19"
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
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

