
+++
authors = ["Crafted by Me"]
title = "Leetcode 201: Bitwise AND of Numbers Range"
date = "2024-04-15"
description = "In-depth solution and explanation for Leetcode 201: Bitwise AND of Numbers Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    
    while(right != left)
    {
        right >>= 1 ;
        left  >>= 1;
        shift++;
    }
    
    return right << shift;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/201.md" >}}
---
{{< youtube vZkutwUrPgE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #202: Happy Number](https://grid47.xyz/posts/leetcode_202) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

