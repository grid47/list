
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1751: Maximum Number of Events That Can Be Attended II"
date = "2020-01-13"
description = "Solution to Leetcode 1751"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> e, mem;
    
    int bs(int num) {
        int ans = e.size();
        int l = 0, r = ans - 1;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(e[mid][0] > num) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid  + 1;
            }
        }
        return ans;
    }
    
    int dp(int idx, int k) {
        if(k == 0 || idx >= e.size()) return 0;
        
        if(mem[idx][k] != -1) return mem[idx][k];
        
        int ans = dp(idx + 1, k);
        
        int nxt = bs(e[idx][1]);
        
        ans = max(ans, dp(nxt, k - 1) + e[idx][2]);
        
        return mem[idx][k] = ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        e = events;
        /*
        max number of events
        pq - pull the ctx back
        start time, end time
        schedule which ends first
        dp - select and omit
        sort - based on end
        dp condition == k return
        binary search to find next event
        sort based on start
        */
        sort(e.begin(), e.end());
        mem.resize(e.size(), vector<int>(k + 1, -1));
        return dp(0, k);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

