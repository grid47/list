
+++
authors = ["Crafted by Me"]
title = "Leetcode 2486: Append Characters to String to Make Subsequence"
date = "2018-01-12"
description = "In-depth solution and explanation for Leetcode 2486: Append Characters to String to Make Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for(int i = 0; i < s.size() && j < t.size(); i++) {
            j += s[i] == t[j];
        }
        return t.size()-j;
    }
};
{{< /highlight >}}


---
{{< youtube gKDmO8ZLRD8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2487: Remove Nodes From Linked List](https://grid47.xyz/posts/leetcode_2487) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

