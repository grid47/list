
+++
authors = ["Yasir"]
title = "Leetcode 459: Repeated Substring Pattern"
date = "2023-07-27"
description = "Solution to Leetcode 459"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/repeated-substring-pattern/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
    }
};
{{< /highlight >}}

