
+++
authors = ["Crafted by Me"]
title = "Leetcode 392: Is Subsequence"
date = "2023-10-07"
description = "Solution to Leetcode 392"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/is-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "") return true;
        int sdx = 0, tdx = 0;
        // sdx is sub seq of tdx

        for(; tdx < t.size(); tdx++) {
            if(t[tdx] == s[sdx]) sdx++;
            if(sdx == s.size()) return true;
        }
        return false;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/392.md" >}}
- by gpt
        
---
{{< youtube M_OB20n4hfo >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

