
+++
authors = ["grid47"]
title = "Leetcode 1846: Maximum Element After Decreasing and Rearranging"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1846: Maximum Element After Decreasing and Rearranging in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        if(arr[0] != 1) arr[0] = 1;
        
        int n = arr.size();
        
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1846.md" >}}
---
{{< youtube o_hVl8IXuIE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1848: Minimum Distance to the Target Element](https://grid47.xyz/posts/leetcode-1848-minimum-distance-to-the-target-element-solution/) |
| --- |
