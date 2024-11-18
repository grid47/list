
+++
authors = ["grid47"]
title = "Leetcode 1130: Minimum Cost Tree From Leaf Values"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1130: Minimum Cost Tree From Leaf Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int res = 0;
        
        vector<int> stk = { INT_MAX };
        for(int a : arr) {
            while(stk.back() <= a) {
                int mid = stk.back();
                stk.pop_back();
                res += mid * min(stk.back(), a);
            }
            stk.push_back(a);
        }
        
        for(int i = 2; i < stk.size(); i++) {
            res += stk[i] * stk[i - 1];
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1130.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1131: Maximum of Absolute Value Expression](https://grid47.xyz/leetcode/solution-1131-maximum-of-absolute-value-expression/) |
| --- |
