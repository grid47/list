
+++
authors = ["Crafted by Me"]
title = "Leetcode 664: Strange Printer"
date = "2023-01-08"
description = "In-depth solution and explanation for Leetcode 664: Strange Printer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/strange-printer/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> memo;
    string s;
    
    int dp(int l, int r) {
        if(l > r) return 0;
        
        if(memo[l][r] != -1) return memo[l][r];
        
        int ans = 1 + dp(l + 1, r);
        
        for(int i = l + 1; i <= r; i++) {
            if(s[i] == s[l])
            ans = min(ans, dp(l + 1, i) + dp(i + 1, r));
        }
        
        
        return memo[l][r] = ans;
    }
    
    
    int strangePrinter(string s) {
        /*
              _ _ _ _     _
            _ _ _ _ _ _ _  
        _ _ _ _ _ _ _ _ _ _
        */
        memo.resize(s.size(), vector<int>(s.size(), -1));
        this->s = s;
        return dp(0, s.size() - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/664.md" >}}
---
{{< youtube fIOZkIH5PZU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #665: Non-decreasing Array](https://grid47.xyz/posts/leetcode_665) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

