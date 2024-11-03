
+++
authors = ["Crafted by Me"]
title = "Leetcode 139: Word Break"
date = "2024-06-16"
description = "In-depth solution and explanation for Leetcode 139: Word Break in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/word-break/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> memo;
    bool wordBreak(string s, vector<string>& dict) {
        map<string, bool> mp;
        for(string d: dict)
            mp[d] = true;
        memo.resize(s.size(), -1);
        return bt(s, 0, mp);
    }
    
    bool bt(string s, int idx, map<string, bool> &mp) {
        
        if(idx == s.size()) return true;
        
        if(memo[idx] != -1) return memo[idx];
        
        for(int i = idx; i < s.size(); i++) {
            if(mp.count(s.substr(idx, i - idx + 1)) && bt(s, i + 1, mp))
                return memo[idx] = true;
        }
        
        return memo[idx] = false;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/139.md" >}}
---
{{< youtube t0svbzZ1PWM >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

