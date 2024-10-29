
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1844: Replace All Digits with Characters"
date = "2019-10-13"
description = "Solution to Leetcode 1844"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-all-digits-with-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string replaceDigits(string s) {
    for (auto i = 1; i < s.size(); i += 2)
        s[i] += s[i - 1] - '0';
        return s;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

