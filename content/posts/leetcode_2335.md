
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2335: Minimum Amount of Time to Fill Cups"
date = "2018-06-09"
description = "Solution to Leetcode 2335"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int fillCups(vector<int>& A) {
        int mx = 0, sum = 0;
        for(int& a: A) {
            mx = max(a, mx);
            sum += a;
        }
        return max(mx, (sum + 1) / 2);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

