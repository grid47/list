
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2194: Cells in a Range on an Excel Sheet"
date = "2018-10-27"
description = "Solution to Leetcode 2194"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> cellsInRange(string s) {
    vector<string> res;
    for (char c = s[0]; c <= s[3]; ++c)
        for (char r = s[1]; r <= s[4]; ++r)
            res.push_back({c, r});
    return res;
}
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

