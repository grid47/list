
+++
authors = ["Crafted by Me"]
title = "Leetcode 712: Minimum ASCII Delete Sum for Two Strings"
date = "2021-11-20"
description = "Solution to Leetcode 712"
tags = [
    
]
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

