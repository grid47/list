
+++
authors = ["grid47"]
title = "Leetcode 1945: Sum of Digits of String After Convert"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1945: Sum of Digits of String After Convert in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getLucky(string s, int k) {
        string tmp;
        for (char c : s) tmp += to_string(c - 'a' + 1);
        int n = 0;
        for (char c : tmp) n += c - '0';
        for (int i = 1; i < k; ++i) {
            int next = 0;
            while (n) {
                next += n % 10;
                n /= 10;
            }
            n = next;
        }
        return n;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1945.md" >}}
---
{{< youtube KN4WAH95RIo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1947: Maximum Compatibility Score Sum](https://grid47.xyz/posts/leetcode-1947-maximum-compatibility-score-sum-solution/) |
| --- |
