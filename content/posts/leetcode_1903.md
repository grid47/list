
+++
authors = ["Yasir"]
title = "Leetcode 1903: Largest Odd Number in String"
date = "2019-08-13"
description = "Solution to Leetcode 1903"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-odd-number-in-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        for(int i = num.size(); i >= 0; i--) {
            if((num[i] - '0') % 2)
              return num.substr(0, i + 1);
        }
        return string();
    }
};
{{< /highlight >}}

