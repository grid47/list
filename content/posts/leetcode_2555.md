
+++
authors = ["Yasir"]
title = "Leetcode 2555: Maximize Win From Two Segments"
date = "2017-10-30"
description = "Solution to Leetcode 2555"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-win-from-two-segments/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {
        
        int n = pos.size(), res = 0;
        
        vector<int> dp(n + 1, 0);
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(pos[j] < pos[i] - k) j++;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1+ dp[j]);
        }
        
        
        return res;
    }
};
{{< /highlight >}}

