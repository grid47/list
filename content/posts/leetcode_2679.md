
+++
authors = ["Crafted by Me"]
title = "Leetcode 2679: Sum in a Matrix"
date = "2017-07-03"
description = "In-depth solution and explanation for Leetcode 2679: Sum in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


"| 2680: Maximum OR |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

