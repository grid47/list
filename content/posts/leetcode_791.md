
+++
authors = ["Crafted by Me"]
title = "Leetcode 791: Custom Sort String"
date = "2022-09-03"
description = "Solution to Leetcode 791"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/custom-sort-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string customSortString(string o, string s) {
        
        unordered_map<char, int> mp;
        for(int i = 0; i < o.size(); i++)
            mp[o[i]] = i + 1;
        
        sort(s.begin(), s.end(), [&](char a, char b) {
            return mp[a] < mp[b];
        });
        
        return s;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/791.md" >}}
- by gpt
        
---
{{< youtube HQ4U24lRar8 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

