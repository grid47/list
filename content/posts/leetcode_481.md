
+++
authors = ["Yasir"]
title = "Leetcode 481: Magical String"
date = "2023-07-05"
description = "Solution to Leetcode 481"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/magical-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while(s.size() < n)
        s += string(s[i++] - '0', s.back() ^ 3);
        return count(s.begin(), s.begin() + n, '1');
    }
};
{{< /highlight >}}

