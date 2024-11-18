
+++
authors = ["grid47"]
title = "Leetcode 1997: First Day Where You Have Been in All the Rooms"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1997: First Day Where You Have Been in All the Rooms in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1997.md" >}}
---
{{< youtube GYyHxkGO4J0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2000: Reverse Prefix of Word](https://grid47.xyz/leetcode/solution-2000-reverse-prefix-of-word/) |
| --- |
