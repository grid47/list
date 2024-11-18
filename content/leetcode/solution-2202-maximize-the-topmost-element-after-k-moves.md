
+++
authors = ["grid47"]
title = "Leetcode 2202: Maximize the Topmost Element After K Moves"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2202: Maximize the Topmost Element After K Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "ViliZpbLtbE"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        int ans = 0;
        
        int n = nums.size();
        
        if (k == 0) return (n >= 1) ? nums[0] : -1;
        if (k == 1) return (n == 1) ? -1 : nums[1];
        if (n == 1) return (k % 2 == 1) ? -1 : nums[0];
        
        int mx = *max_element(begin(nums), begin(nums) + min(n, k - 1));
        if(k < n) mx = max(mx, nums[k]);
        
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2202.md" >}}
---
{{< youtube ViliZpbLtbE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2207: Maximize Number of Subsequences in a String](https://grid47.xyz/leetcode/solution-2207-maximize-number-of-subsequences-in-a-string/) |
| --- |
