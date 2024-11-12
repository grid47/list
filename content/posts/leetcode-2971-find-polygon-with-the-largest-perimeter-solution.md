
+++
authors = ["grid47"]
title = "Leetcode 2971: Find Polygon With the Largest Perimeter"
date = "2024-01-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2971: Find Polygon With the Largest Perimeter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
        for(int i = n - 1; i >= 2; i--)
            if(nums[i] < sum[i - 1])
                return sum[i];
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2971.md" >}}
---
{{< youtube Yk9Mor-Y488 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3005: Count Elements With Maximum Frequency](https://grid47.xyz/posts/leetcode-3005-count-elements-with-maximum-frequency-solution/) |
| --- |
