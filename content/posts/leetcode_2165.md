
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2165: Smallest Value of the Rearranged Number"
date = "2018-11-26"
description = "Solution to Leetcode 2165"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long smallestNumber(long long num) {
        auto s = to_string(abs(num));
        sort(s.begin(), s.end(), [&](char a, char b){
            return num > 0? a < b: b < a;
        });
        if(num > 0)
        swap(s[0], s[s.find_first_not_of('0')]);
        return stoll(s) * (num < 0? -1: 1);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

