
+++
authors = ["Yasir"]
title = "Leetcode 925: Long Pressed Name"
date = "2022-04-18"
description = "Solution to Leetcode 925"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

