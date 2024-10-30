
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 91: Decode Ways"
date = "2024-08-01"
description = "Solution to Leetcode 91"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-ways/description/)

---
{{< youtube 6aEyTjOwlJU >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> memo;
    int numDecodings(string s) {
        
        memo.resize(s.size(), -1);
        return !s.size()? 0: ways(0, s);
    }
    
    int ways(int i, string s) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(memo[i] > -1) return memo[i];
        int res = ways(i + 1, s);
        
        if(i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
            res += ways(i + 2, s);
        
        return memo[i] = res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/91.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

