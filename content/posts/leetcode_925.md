
+++
authors = ["Crafted by Me"]
title = "Leetcode 925: Long Pressed Name"
date = "2022-04-22"
description = "In-depth solution and explanation for Leetcode 925: Long Pressed Name in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/long-pressed-name/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
        bool isLongPressedName(string name, string typed) {
        int i = 0, m = name.length(), n = typed.length();
        for (int j = 0; j < n; ++j)
            if (i < m && name[i] == typed[j])
                ++i;
            else if (!j || typed[j] != typed[j - 1])
                return false;
        return i == m;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/925.md" >}}
---


"| 926: Flip String to Monotone Increasing |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

