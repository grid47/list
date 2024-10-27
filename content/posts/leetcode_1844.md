
+++
authors = ["Yasir"]
title = "Leetcode 1844: Replace All Digits with Characters"
date = "2019-10-11"
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

{{< highlight html >}}
class Solution {
public:
    string replaceDigits(string s) {
    for (auto i = 1; i < s.size(); i += 2)
        s[i] += s[i - 1] - '0';
        return s;
    }
};
{{< /highlight >}}

