
+++
authors = ["Yasir"]
title = "Leetcode 498: Diagonal Traverse"
date = "2023-06-19"
description = "Solution to Leetcode 498"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/diagonal-traverse/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        for(int s = 0; s <= m + n - 2; s++) {
            for(int x = 0; x <= s; x++) {
                int i = x;
                int j = s - i;
                if(s%2 == 0) swap(i, j);
                if(i >= m || j >= n) continue;
                res.push_back(mat[i][j]);
            }
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

