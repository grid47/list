
+++
authors = ["grid47"]
title = "Leetcode 2679: Sum in a Matrix"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2679: Sum in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-in-a-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        int res = 0;
        
        int m = nums.size(), n = nums[0].size();
        
        for(int i = 0; i < m; i++)
        sort(nums[i].rbegin(), nums[i].rend());
        
        for(int i = 0; i < n; i++) {
            int mx = nums[0][i];
            for(int j = 0; j < m; j++) {
                mx = max(mx, nums[j][i]);
            }
            res += mx;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2679.md" >}}
---
{{< youtube oL_BwmPMkng >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2680: Maximum OR](https://grid47.xyz/posts/leetcode-2680-maximum-or-solution/) |
| --- |
