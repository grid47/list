
+++
authors = ["grid47"]
title = "Leetcode 1639: Number of Ways to Form a Target String Given a Dictionary"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1639: Number of Ways to Form a Target String Given a Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string hit;
    int mod = (int) 1e9 + 7;
    vector<vector<int>> frq;
    int memo[1001][1001];
    
    int dp(int fidx, int hidx) {
        if(hidx == hit.size()) return 1;
        if(fidx == frq.size()) return 0;
        
        if(memo[fidx][hidx] != -1) return memo[fidx][hidx];
        
        long ans = dp(fidx + 1, hidx);
        
        int ch = hit[hidx] - 'a';
        if(frq[fidx][ch] > 0) {
            ans = (ans + (long)(frq[fidx][ch] % mod) * (dp(fidx + 1, hidx + 1) % mod)) % mod;
        }
        
        return memo[fidx][hidx] = ans % mod;
    }
    
    int numWays(vector<string>& words, string target) {
        hit = target;
        frq.resize(words[0].size(), vector<int>(26, 0));
        
        for(string s: words)
            for(int i = 0; i < s.size(); i++) {
                frq[i][s[i] - 'a']++;
            }
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1639.md" >}}
---
{{< youtube l10Gtcr_Gqo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1642: Furthest Building You Can Reach](https://grid47.xyz/posts/leetcode_1642) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
