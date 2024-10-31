
+++
authors = ["Crafted by Me"]
title = "Leetcode 1974: Minimum Time to Type Word Using Special Typewriter"
date = "2019-06-07"
description = "Solution to Leetcode 1974"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minTimeToType(string word) {
        int res = word.size(), point = 'a';
        for (auto ch : word) {
            res += min(abs(ch - point), 26 - abs(point - ch));
            point = ch;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

