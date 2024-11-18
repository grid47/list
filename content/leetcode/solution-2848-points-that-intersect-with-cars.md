
+++
authors = ["grid47"]
title = "Leetcode 2848: Points That Intersect With Cars"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2848: Points That Intersect With Cars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "86n-e3Zwx34"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/points-that-intersect-with-cars/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
    vector<int> v(102, 0);
    int ans = 0;
    for(auto n: nums){
        for(int i = n[0]; i <= n[1]; ++i) v[i-1]++;
    }
    for(auto e: v){
        if(e) ans++;
    }
    return ans;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2848.md" >}}
---
{{< youtube 86n-e3Zwx34 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2849: Determine if a Cell Is Reachable at a Given Time](https://grid47.xyz/leetcode/solution-2849-determine-if-a-cell-is-reachable-at-a-given-time/) |
| --- |
