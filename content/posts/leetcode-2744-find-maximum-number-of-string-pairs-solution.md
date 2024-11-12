
+++
authors = ["grid47"]
title = "Leetcode 2744: Find Maximum Number of String Pairs"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2744: Find Maximum Number of String Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
    int vis[676] = {}, res = 0;
    for (const auto &w : words) {
        res += vis[(w[1] - 'a') * 26 + w[0] - 'a'];
        vis[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
    }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2744.md" >}}
---
{{< youtube f8qWoxowloA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2746: Decremental String Concatenation](https://grid47.xyz/posts/leetcode-2746-decremental-string-concatenation-solution/) |
| --- |
