
+++
authors = ["Crafted by Me"]
title = "Leetcode 2319: Check if Matrix Is X-Matrix"
date = "2018-06-27"
description = "Solution to Leetcode 2319"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-matrix-is-x-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& g) {
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j) {
            if (i == j || i + j == g.size() - 1) {
                if (g[i][j] == 0)
                    return false;
            }
            else if (g[i][j] > 0)
                return false;
        }
    return true;
}
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

