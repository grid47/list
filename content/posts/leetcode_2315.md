
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2315: Count Asterisks"
date = "2018-06-30"
description = "Solution to Leetcode 2315"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-asterisks/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
int countAsterisks(string s) {
        int res = 0, sign = 1;
        for (char& c : s)
            if ((sign ^= c == '|') && c == '*')
                res++;
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

