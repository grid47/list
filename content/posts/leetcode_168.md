
+++
authors = ["Yasir"]
title = "Leetcode 168: Excel Sheet Column Title"
date = "2024-05-13"
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

{{< highlight html >}}
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

