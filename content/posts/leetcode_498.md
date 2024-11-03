
+++
authors = ["Crafted by Me"]
title = "Leetcode 498: Diagonal Traverse"
date = "2023-06-23"
description = "In-depth solution and explanation for Leetcode 498: Diagonal Traverse in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube xio2uEQQPZQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #499: The Maze III](https://grid47.xyz/posts/leetcode_499) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

