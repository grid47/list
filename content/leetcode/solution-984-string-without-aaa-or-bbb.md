
+++
authors = ["grid47"]
title = "Leetcode 984: String Without AAA or BBB"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 984: String Without AAA or BBB in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/string-without-aaa-or-bbb/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
        if(B > A) return strWithout3a3b(B, A, b, a);
        while(A-- > 0) {
            res += a;
            if(A > B) res += a, A--;
            if(B-->0) res += b;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/984.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #985: Sum of Even Numbers After Queries](https://grid47.xyz/leetcode/solution-985-sum-of-even-numbers-after-queries/) |
| --- |
