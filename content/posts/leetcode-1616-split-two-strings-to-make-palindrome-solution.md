
+++
authors = ["grid47"]
title = "Leetcode 1616: Split Two Strings to Make Palindrome"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1616: Split Two Strings to Make Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1620: Coordinate With Maximum Network Quality](https://grid47.xyz/posts/leetcode-1616-split-two-strings-to-make-palindrome-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
