
+++
authors = ["Crafted by Me"]
title = "Leetcode 97: Interleaving String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 97: Interleaving String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/interleaving-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s1, s2, s3;
    vector<vector<int>> memo;
    bool dp(int i, int j) {
        if(i == s1.size() && j == s2.size()) return true;

        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        int k = i + j;
        if(i < s1.size() && s1[i] == s3[k])
            ans |= dp(i + 1, j);
        
        if(j < s2.size() && s2[j] == s3[k])
            ans |= dp(i, j + 1);
        
        return memo[i][j] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        if(s1.size() + s2.size() != s3.size()) return false;
        memo.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/97.md" >}}
---
{{< youtube 3Rw3p9LrgvE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #98: Validate Binary Search Tree](https://grid47.xyz/posts/leetcode_98) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
