
+++
authors = ["grid47"]
title = "Leetcode 712: Minimum ASCII Delete Sum for Two Strings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 712: Minimum ASCII Delete Sum for Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s1, s2;
    vector<vector<int>> mem;
    
    int dp(int i, int j) {
        if(i == s1.size() || j == s2.size()) return 0;
        
        if(mem[i][j] != -1) return mem[i][j];
        
        int ans = max(dp(i + 1, j), dp(i, j + 1));
        if(s1[i] == s2[j]) {
            ans = max(ans, dp(i + 1, j + 1) + s1[i]);
        }
        
        return mem[i][j] = ans;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        
        this->s1 = s1;
        this->s2 = s2;
        
        int ans = 0;
        for(int i = 0; i < s1.size(); i++)
            ans += s1[i];
        for(int i = 0; i < s2.size(); i++)
            ans += s2[i];
        
        mem.resize(s1.size() + 1, vector<int>(s2.size(), -1));
        
        return ans - 2 * dp(0, 0);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/712.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #713: Subarray Product Less Than K](https://grid47.xyz/posts/leetcode-713-subarray-product-less-than-k-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
