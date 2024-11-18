
+++
authors = ["grid47"]
title = "Leetcode 1017: Convert to Base -2"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1017: Convert to Base -2 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/convert-to-base-2/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string baseNeg2(int n) {
        string res = "";

        while(n) {
            res = to_string(n&1) + res;
            n = -(n >> 1);
        }

        return res == ""? "0":res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1017.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1019: Next Greater Node In Linked List](https://grid47.xyz/leetcode/solution-1019-next-greater-node-in-linked-list/) |
| --- |
