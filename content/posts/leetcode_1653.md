
+++
authors = ["Crafted by Me"]
title = "Leetcode 1653: Minimum Deletions to Make String Balanced"
date = "2020-04-24"
description = "In-depth solution and explanation for Leetcode 1653: Minimum Deletions to Make String Balanced in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), bcnt = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; i++) {
            char a = s[i];
            if(a == 'a') {                
                dp[i + 1] = min(dp[i] + 1, bcnt);
            } else {
                bcnt++;
                dp[i + 1] = dp[i];
            }
        }
        return dp[n];
    }
};
{{< /highlight >}}


---


"| 1654: Minimum Jumps to Reach Home |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

