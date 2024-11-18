
+++
authors = ["grid47"]
title = "Leetcode 624: Maximum Distance in Arrays"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 624: Maximum Distance in Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "J0yYlj_oVTI"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/624.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-distance-in-arrays/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/624.webp" 
    alt="Two arrays with the maximum distance between values highlighted, glowing as the distance is found."
    caption="Solution to LeetCode 624: Maximum Distance in Arrays Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, mn = 10000, mx = -10000;
        for (auto& a : arrays) {
            res = max(res, max(a.back()-mn, mx-a.front()));
            mn = min(mn, a.front()), mx = max(mx, a.back());
        }
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/624.md" >}}
---
{{< youtube J0yYlj_oVTI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #627: Swap Salary](https://grid47.xyz/leetcode/solution-627-swap-salary/) |
| --- |
