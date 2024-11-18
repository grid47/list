
+++
authors = ["grid47"]
title = "Leetcode 1871: Jump Game VII"
date = "2024-05-03"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1876: Substrings of Size Three with Distinct Characters](https://grid47.xyz/leetcode/solution-1876-substrings-of-size-three-with-distinct-characters/) |
| --- |
