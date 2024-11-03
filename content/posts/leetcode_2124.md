
+++
authors = ["Crafted by Me"]
title = "Leetcode 2124: Check if All A's Appears Before All B's"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2124: Check if All A's Appears Before All B's in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
bool checkString(string s) {
        return s.find("ba")==string::npos;
    }
};
{{< /highlight >}}


---
{{< youtube RgzM3HRkdp8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2125: Number of Laser Beams in a Bank](https://grid47.xyz/posts/leetcode_2125) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

