
+++
authors = ["Crafted by Me"]
title = "Leetcode 2033: Minimum Operations to Make a Uni-Value Grid"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2033: Minimum Operations to Make a Uni-Value Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m = grid.size(), n = grid[0].size();
        
        int num = grid[0][0];
        
        vector<int> arr;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            arr.push_back(grid[i][j]);
            if(abs(num - grid[i][j]) % x != 0) return -1;
        }
        
        sort(arr.begin(), arr.end());
        
        int pos = arr.size() / 2;

        int res = 0;
        for(int i = 0; i < arr.size(); i++)        
            res += (abs(arr[pos] - arr[i]) / x);
        
        return res;
        
    }
};
{{< /highlight >}}


---
{{< youtube c90k-5HigWs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2034: Stock Price Fluctuation ](https://grid47.xyz/posts/leetcode_2034) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

