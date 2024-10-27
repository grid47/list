
+++
authors = ["Yasir"]
title = "Leetcode 2194: Cells in a Range on an Excel Sheet"
date = "2018-10-26"
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

{{< highlight html >}}
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

