
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2124: Check if All A's Appears Before All B's"
date = "2019-01-05"
description = "Solution to Leetcode 2124"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

