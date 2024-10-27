
+++
authors = ["Yasir"]
title = "Leetcode 435: Non-overlapping Intervals"
date = "2023-08-20"
description = "Solution to Leetcode 435"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/non-overlapping-intervals/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ivl) {
        sort(ivl.begin(), ivl.end());
        int ans = 0;
        int n = ivl.size();
        int prv = 0;
        for(int cur = 1; cur < n; cur++) {
            // [1, 5]. [3, 6]
            // [2, 8]. [3, 5]
            if(ivl[cur][0] < ivl[prv][1]) {
                ans++;
                if(ivl[cur][1] <= ivl[prv][1])
                    prv = cur;
            } else {
                prv = cur;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

