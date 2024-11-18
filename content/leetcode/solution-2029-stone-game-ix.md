
+++
authors = ["grid47"]
title = "Leetcode 2029: Stone Game IX"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2029: Stone Game IX in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Counting","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "7r34JD5ud-c"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-ix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> m(3, 0);
        for(int a: stones)
        m[a % 3]++;
        if(min(m[2], m[1]) == 0)
        return max(m[1], m[2]) > 2 && m[0] % 2 >0;
        return abs(m[1] - m[2]) > 2 || m[0] % 2 == 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2029.md" >}}
---
{{< youtube 7r34JD5ud-c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2033: Minimum Operations to Make a Uni-Value Grid](https://grid47.xyz/leetcode/solution-2033-minimum-operations-to-make-a-uni-value-grid/) |
| --- |
