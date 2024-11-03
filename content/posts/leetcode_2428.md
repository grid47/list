
+++
authors = ["Crafted by Me"]
title = "Leetcode 2428: Maximum Sum of an Hourglass"
date = "2018-03-11"
description = "In-depth solution and explanation for Leetcode 2428: Maximum Sum of an Hourglass in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

| Next : [LeetCode #2429: Minimize XOR](https://grid47.xyz/posts/leetcode_2429) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

