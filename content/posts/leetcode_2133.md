
+++
authors = ["Crafted by Me"]
title = "Leetcode 2133: Check if Every Row and Column Contains All Numbers"
date = "2018-12-31"
description = "In-depth solution and explanation for Leetcode 2133: Check if Every Row and Column Contains All Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkValid(vector<vector<int>>& mtx) {
        int n = mtx.size();
        for(int i = 0; i < n; i++) {
          bitset<101> row, col;
          for(int j = 0; j < n; j++)
            row[mtx[i][j]] = col[mtx[j][i]] = true;
          if (min(row.count(), col.count()) < n)
            return false;
        }
        return true;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2134: Minimum Swaps to Group All 1's Together II](grid47.xyz/leetcode_2134) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

