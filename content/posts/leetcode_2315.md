
+++
authors = ["Yasir"]
title = "Leetcode 2315: Count Asterisks"
date = "2018-06-28"
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

{{< highlight html >}}
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
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

