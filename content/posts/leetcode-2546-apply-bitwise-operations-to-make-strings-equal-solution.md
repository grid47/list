
+++
authors = ["grid47"]
title = "Leetcode 2546: Apply Bitwise Operations to Make Strings Equal"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2546: Apply Bitwise Operations to Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        return (s.find('1') != string::npos) == (target.find('1') != string::npos);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2546.md" >}}
---
{{< youtube 9aTO0sRtL-s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2549: Count Distinct Numbers on Board](https://grid47.xyz/posts/leetcode-2549-count-distinct-numbers-on-board-solution/) |
| --- |
