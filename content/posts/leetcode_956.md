
+++
authors = ["Yasir"]
title = "Leetcode 956: Tallest Billboard"
date = "2022-03-16"
description = "Solution to Leetcode 956"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/tallest-billboard/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> rods;
    vector<map<int, int>> mem;
    
    int dp(int idx, int diff) {
        if(idx == rods.size()) return diff == 0? 0: INT_MIN;
        if(mem[idx].count(diff)) return mem[idx][diff];

        int ans = dp(idx + 1, diff);
        ans = max(ans, rods[idx] + dp(idx + 1, diff + rods[idx]));
        ans = max(ans, (rods[idx]> diff? rods[idx] - diff:0) + dp(idx + 1, abs(diff - rods[idx])));

        return mem[idx][diff] = ans;
    }
    
    int tallestBillboard(vector<int>& rods) {
        this->rods =rods;
        mem.resize(rods.size());
        return dp(0, 0);
    }
};
{{< /highlight >}}

