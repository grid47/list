
+++
authors = ["Yasir"]
title = "Leetcode 2278: Percentage of Letter in String"
date = "2018-08-04"
description = "Solution to Leetcode 2278"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/percentage-of-letter-in-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int percentageLetter(string s, char letter) {
        return 100 * count(begin(s), end(s), letter) / s.size();
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

