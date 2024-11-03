
+++
authors = ["Crafted by Me"]
title = "Leetcode 1945: Sum of Digits of String After Convert"
date = "2019-07-07"
description = "In-depth solution and explanation for Leetcode 1945: Sum of Digits of String After Convert in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


| Next : [LeetCode #1946: Largest Number After Mutating Substring](grid47.xyz/leetcode_1946) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

