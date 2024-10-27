
+++
authors = ["Yasir"]
title = "Leetcode 1997: First Day Where You Have Been in All the Rooms"
date = "2019-05-11"
description = "Solution to Leetcode 1997"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int n;
    
    int firstDayBeenInAllRooms(vector<int>& nxt) {
        n = nxt.size();
        int mod = (int) 1e9 + 7;
        vector<long long> dp(n, 0); // step
        for(int i = 1; i < n; i++)
            dp[i] = (dp[i - 1] + 1 + (dp[i - 1] - dp[nxt[i - 1]]) + 1 + mod) % mod;
        
        return dp[n - 1];
    }
};
{{< /highlight >}}

