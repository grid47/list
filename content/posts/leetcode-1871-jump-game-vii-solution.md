
+++
authors = ["grid47"]
title = "Leetcode 1871: Jump Game VII"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1871: Jump Game VII in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-vii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canReach(string s, int mnj, int mxj) {
        int n = s.length();
        vector<bool> dp(n, false);
        dp[0] = true;
        int pre = 0;
        for(int i = 0; i < n; i++) {
        
            if(i >= mnj && dp[i - mnj])
                pre++;

            if(i > mxj && dp[i - mxj -1])
                pre--;

            if (pre > 0) dp[i] = s[i] == '0';       
        }
        return dp[n - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1871.md" >}}
---
{{< youtube v1HpZUnQ4Yo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1876: Substrings of Size Three with Distinct Characters](https://grid47.xyz/posts/leetcode-1876-substrings-of-size-three-with-distinct-characters-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}