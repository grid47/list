
+++
authors = ["grid47"]
title = "Leetcode 2266: Count Number of Texts"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2266: Count Number of Texts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-texts/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1e9 + 7;
public:
    int countTexts(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] % mod;
            if(i > 1 && s[i - 1] == s[i - 2]) {
                dp[i] = (dp[i] + dp[i - 2]) % mod;
                if(i > 2 && s[i - 1] == s[i - 3]) {
                    dp[i] = (dp[i] + dp[i - 3]) % mod;
                    if(i > 3 && (s[i-1]=='7' || s[i-1]=='9') && s[i - 1] == s[i - 4]) {
                        dp[i] = (dp[i] + dp[i - 4]) % mod;                        
                    }
                }
            }
        }

        return dp[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2266.md" >}}
---
{{< youtube LdM0WLfhF_4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2267:  Check if There Is a Valid Parentheses String Path](https://grid47.xyz/posts/leetcode_2267) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
