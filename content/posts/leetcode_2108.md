
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2108: Find First Palindromic String in the Array"
date = "2019-01-21"
description = "Solution to Leetcode 2108"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &w : words)
            if (w == string(rbegin(w), rend(w)))
                return w;
        return "";
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

