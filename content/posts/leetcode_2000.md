
+++
authors = ["Crafted by Me"]
title = "Leetcode 2000: Reverse Prefix of Word"
date = "2019-05-13"
description = "In-depth solution and explanation for Leetcode 2000: Reverse Prefix of Word in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-prefix-of-word/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto p = word.find(ch);
        if (p != string::npos)
            reverse(begin(word), begin(word) + p + 1);
        return word;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2000.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2001: Number of Pairs of Interchangeable Rectangles](https://grid47.xyz/posts/leetcode_2001) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

