
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1893: Check if All the Integers in a Range Are Covered"
date = "2019-08-25"
description = "Solution to Leetcode 1893"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int line[52] = {};
        for (auto &r : ranges) {
            line[r[0]] += 1;
            line[r[1] + 1] -= 1;
        }
        for (int i = 1, overlaps = 0; i <= right; ++i) {
            overlaps += line[i];
            if (i >= left && overlaps == 0)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

