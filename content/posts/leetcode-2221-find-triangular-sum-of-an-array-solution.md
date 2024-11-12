
+++
authors = ["grid47"]
title = "Leetcode 2221: Find Triangular Sum of an Array"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2221: Find Triangular Sum of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-triangular-sum-of-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);        
        for(int i = n; i > 1; i--) {
            int k = i - 1;
            for(int j = k - 1; j >= 0; j--)
                arr[j] = (nums[j] % 10 + nums[j + 1] % 10) % 10;
            
            nums = arr;
        }
        
        return nums[0];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2221.md" >}}
---
{{< youtube K-IoQp07D8c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2222: Number of Ways to Select Buildings](https://grid47.xyz/posts/leetcode-2222-number-of-ways-to-select-buildings-solution/) |
| --- |
