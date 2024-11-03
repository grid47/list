
+++
authors = ["Crafted by Me"]
title = "Leetcode 2108: Find First Palindromic String in the Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2108: Find First Palindromic String in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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


---
{{< youtube 4JA5MW772N0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2109: Adding Spaces to a String](https://grid47.xyz/posts/leetcode_2109) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

