
+++
authors = ["grid47"]
title = "Leetcode 1503: Last Moment Before All Ants Fall Out of a Plank"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1503: Last Moment Before All Ants Fall Out of a Plank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Brainteaser","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int mx = 0;
        for(int i = 0; i < right.size(); i++)
            mx = max(mx, n - right[i]);
        
        for(int i = 0; i < left.size(); i++)
            mx = max(mx, left[i]);        
        
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1503.md" >}}
---
{{< youtube tl0akFR9IXQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1504: Count Submatrices With All Ones](https://grid47.xyz/leetcode/solution-1504-count-submatrices-with-all-ones/) |
| --- |
