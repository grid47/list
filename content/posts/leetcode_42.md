
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 42: Trapping Rain Water"
date = "2024-09-17"
description = "Solution to Leetcode 42"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/trapping-rain-water/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int trap(vector<int>& n) {
        int l = 0, r = n.size() - 1, ans = 0, ml = 0, mr = 0;
        while (l < r)
            if (n[l] < n[r]) ans += (ml = max(ml, n[l])) - n[l++];
            else ans += (mr = max(mr, n[r])) - n[r--];
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

