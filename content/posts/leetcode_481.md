
+++
authors = ["Crafted by Me"]
title = "Leetcode 481: Magical String"
date = "2023-07-10"
description = "Solution to Leetcode 481"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/magical-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while(s.size() < n)
        s += string(s[i++] - '0', s.back() ^ 3);
        return count(s.begin(), s.begin() + n, '1');
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/481.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

