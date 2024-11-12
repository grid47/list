
+++
authors = ["grid47"]
title = "Leetcode 498: Diagonal Traverse"
date = "2024-09-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 498: Diagonal Traverse in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/diagonal-traverse/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/498.webp" 
    alt="A matrix where elements are traversed diagonally, each element softly glowing as it is visited."
    caption="Solution to LeetCode 498: Diagonal Traverse Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #501: Find Mode in Binary Search Tree](https://grid47.xyz/posts/leetcode-501-find-mode-in-binary-search-tree-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
