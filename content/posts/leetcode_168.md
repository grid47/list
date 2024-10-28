
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 168: Excel Sheet Column Title"
date = "2024-05-14"
description = "Solution to Leetcode 168"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/excel-sheet-column-title/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int mod;
        while(columnNumber > 0) {
            mod = --columnNumber % 26;
            char x = ('A' + mod);
            res = x + res;
            columnNumber /= 26;
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

