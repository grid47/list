
+++
authors = ["grid47"]
title = "Leetcode 2697: Lexicographically Smallest Palindrome"
date = "2024-02-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2697: Lexicographically Smallest Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographically-smallest-palindrome/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        
        while(i < j) {
            char tmp = min(s[i], s[j]);
            s[i] = s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2697.md" >}}
---
{{< youtube EzAjKrEQLFs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2706: Buy Two Chocolates](https://grid47.xyz/posts/leetcode-2706-buy-two-chocolates-solution/) |
| --- |
