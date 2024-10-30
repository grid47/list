
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 139: Word Break"
date = "2024-06-14"
description = "Solution to Leetcode 139"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/word-break/description/)

---
{{< youtube t0svbzZ1PWM >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

