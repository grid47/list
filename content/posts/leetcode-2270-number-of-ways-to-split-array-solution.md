
+++
authors = ["grid47"]
title = "Leetcode 2270: Number of Ways to Split Array"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2270: Number of Ways to Split Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-split-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int waysToSplitArray(vector<int>& in) {
        
        
        // partial_sum(nums.begin(), nums.end(), nums.begin());
        
        int n = in.size(), res = 0;

        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
        nums[i] = (i == 0) ? in[0] : nums[i - 1] + in[i];
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] >= nums[n - 1] - nums[i]) res++;
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2270.md" >}}
---
{{< youtube XdsMrB7WRUw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2271: Maximum White Tiles Covered by a Carpet](https://grid47.xyz/posts/leetcode-2271-maximum-white-tiles-covered-by-a-carpet-solution/) |
| --- |
