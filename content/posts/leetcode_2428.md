
+++
authors = ["Crafted by Me"]
title = "Leetcode 2428: Maximum Sum of an Hourglass"
date = "2018-03-10"
description = "Solution to Leetcode 2428"
tags = [
    
]
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



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

