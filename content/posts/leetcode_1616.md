
+++
authors = ["Crafted by Me"]
title = "Leetcode 1616: Split Two Strings to Make Palindrome"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1616: Split Two Strings to Make Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-two-strings-to-make-palindrome/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }

    bool check(string a, string b) {
        int i = 0, j = a.size() -1;
        while(i < j && a[i] == b[j])
        i++, j--;
        return isPalindrom(a, i, j) || isPalindrom(b, i, j);
    }

    bool isPalindrom(string a, int i , int j) {
        while(i < j && a[i] == a[j])
        i++, j--;
        return i >= j;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1616.md" >}}
---
{{< youtube s0UlCe7icxs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1617: Count Subtrees With Max Distance Between Cities](https://grid47.xyz/posts/leetcode_1617) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

