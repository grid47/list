
+++
authors = ["Crafted by Me"]
title = "Leetcode 498: Diagonal Traverse"
date = "2023-06-23"
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

{{< highlight cpp >}}
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/498.md" >}}
- by gpt
        
---
{{< youtube xio2uEQQPZQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

