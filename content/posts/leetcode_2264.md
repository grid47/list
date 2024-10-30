
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2264: Largest 3-Same-Digit Number in String"
date = "2018-08-20"
description = "Solution to Leetcode 2264"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestGoodInteger(string num) {
        char res = 0;
    for(int i = 2; i < num.size(); ++i)
        if (num[i] == num[i - 1] && num[i] == num[i - 2])
            res = max(res, num[i]);
    return res == 0 ? "" : string(3, res);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

