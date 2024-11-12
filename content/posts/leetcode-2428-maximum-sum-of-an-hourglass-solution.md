
+++
authors = ["grid47"]
title = "Leetcode 2428: Maximum Sum of an Hourglass"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2428: Maximum Sum of an Hourglass in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i = 1; i < m - 1; i++)
        for(int j = 1; j < n - 1; j++) {
            
            int sum = grid[i][j] + grid[i - 1][j] + grid[i + 1][j] +
                grid[i - 1][j - 1] + grid[i - 1][j + 1] +
                grid[i + 1][j - 1] + grid[i + 1][j + 1];
            
            ans = max(ans, sum);
            
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2428.md" >}}
---
{{< youtube u4dYdiBXAjI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2429: Minimize XOR](https://grid47.xyz/posts/leetcode-2429-minimize-xor-solution/) |
| --- |
