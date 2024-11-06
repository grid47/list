
+++
authors = ["Crafted by Me"]
title = "Leetcode 730: Count Different Palindromic Subsequences"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 730: Count Different Palindromic Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-different-palindromic-subsequences/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return dp(0, n - 1, memo, s);
    }
    
    
    int dp(int i, int j, vector<vector<int>> &memo, string &s) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(memo[i][j] != 0) return memo[i][j];
        
        long long ans = 0;
        if(s[i] == s[j]) {
            ans = 2 * dp(i + 1, j - 1, memo, s);
            int left = i + 1, right = j - 1;
            while(left <= right && s[left] != s[i]) left++;
            while(left <= right && s[right] != s[i]) right--;
            if(left < right) ans -= dp(left + 1, right - 1, memo, s);
            else if(left == right) ans += 1;
            else ans += 2;
        } else {
            ans = dp(i + 1, j, memo, s) + dp(i, j - 1, memo, s) - dp(i + 1, j - 1, memo, s);
        }
        return memo[i][j] = ans < 0? ans + mod: ans % mod;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/730.md" >}}
---
{{< youtube mAEhMxPHOyc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #731: My Calendar II](https://grid47.xyz/posts/leetcode_731) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

