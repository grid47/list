
+++
authors = ["Yasir"]
title = "Leetcode 42: Trapping Rain Water"
date = "2024-09-15"
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

{{< highlight html >}}
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

