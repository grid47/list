
+++
authors = ["Yasir"]
title = "Leetcode 2108: Find First Palindromic String in the Array"
date = "2019-01-20"
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

{{< highlight html >}}
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

