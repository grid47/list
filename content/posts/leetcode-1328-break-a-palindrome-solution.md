
+++
authors = ["grid47"]
title = "Leetcode 1328: Break a Palindrome"
date = "2024-06-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1328: Break a Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/break-a-palindrome/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        for(int i = 0; i < n / 2; i++) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return n < 2 ? "" : palindrome;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1328.md" >}}
---
{{< youtube B5v5rDR7c9A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1329: Sort the Matrix Diagonally](https://grid47.xyz/posts/leetcode-1329-sort-the-matrix-diagonally-solution/) |
| --- |
