
+++
authors = ["Yasir"]
title = "Leetcode 2264: Largest 3-Same-Digit Number in String"
date = "2018-08-17"
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

{{< highlight html >}}
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

