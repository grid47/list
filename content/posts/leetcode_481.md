
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 481: Magical String"
date = "2023-07-06"
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

{{< highlight cpp >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

