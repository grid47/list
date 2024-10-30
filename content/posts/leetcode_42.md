
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 42: Trapping Rain Water"
date = "2024-09-19"
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
{{< youtube nan >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/42.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

