
+++
authors = ["Crafted by Me"]
title = "Leetcode 2188: Minimum Time to Finish the Race"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2188: Minimum Time to Finish the Race in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-finish-the-race/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int mx_lap = 0;
    int dp[1001] = {}, best[1001] = {};
    
    int dfs(int lap, int cT) {
        if(lap == 0) return -cT;
        if(dp[lap]) return dp[lap];
        
        int ans = INT_MAX;
        for(int i = 1; i <= min(mx_lap, lap); i++) {
            ans = min(ans, best[i] + cT + dfs(lap - i, cT));
        }
        return dp[lap] = ans;
    }
    
    int minimumFinishTime(vector<vector<int>>& tires, int cT, int numLaps) {

        for(auto it: tires) {
            long long time = it[0], exp = it[0];
            for(int lap = 1; lap <= numLaps && exp < it[0] + cT; lap++) {
                
                mx_lap = max(mx_lap, lap);
                
                if(best[lap] == 0 || best[lap] > time)
                    best[lap] = time;
                
                exp *= it[1];
                time += exp;
            }
        }

        return dfs(numLaps, cT);
    }
};
{{< /highlight >}}


---
{{< youtube GqQISf5I4kk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2189: Number of Ways to Build House of Cards](https://grid47.xyz/posts/leetcode_2189) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
