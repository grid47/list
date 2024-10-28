
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1702: Maximum Binary String After Change"
date = "2020-03-02"
description = "Solution to Leetcode 1702"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-binary-string-after-change/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string maximumBinaryString(string binary) {
        int ones = 0, zeros = 0, n = binary.size();
        for (auto &c: binary) {
            if(c == '0')
            zeros++;
            else if (zeros == 0)
            ones++;
            c = '1';
        }
        if(ones < n)
        binary[zeros + ones -1] = '0';
        return binary;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

