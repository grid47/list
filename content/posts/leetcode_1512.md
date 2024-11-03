
+++
authors = ["Crafted by Me"]
title = "Leetcode 1512: Number of Good Pairs"
date = "2020-09-12"
description = "In-depth solution and explanation for Leetcode 1512: Number of Good Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-pairs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> count;
        for (int a: A) {
            res += count[a]++;
        }
        return res;   
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1512.md" >}}
---
{{< youtube BqhDFUo1rjs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1513: Number of Substrings With Only 1s](https://grid47.xyz/posts/leetcode_1513) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

