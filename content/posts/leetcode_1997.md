
+++
authors = ["Crafted by Me"]
title = "Leetcode 1997: First Day Where You Have Been in All the Rooms"
date = "2019-05-16"
description = "In-depth solution and explanation for Leetcode 1997: First Day Where You Have Been in All the Rooms in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1998: GCD Sort of an Array](https://grid47.xyz/posts/leetcode_1998) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

