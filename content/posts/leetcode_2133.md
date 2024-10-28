
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2133: Check if Every Row and Column Contains All Numbers"
date = "2018-12-27"
description = "Solution to Leetcode 2133"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

