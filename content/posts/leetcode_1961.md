
+++
authors = ["Crafted by Me"]
title = "Leetcode 1961: Check If String Is a Prefix of Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1961: Check If String Is a Prefix of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPrefixString(string s, vector<string>& w) {
        int k = 0, l = 0, i = 0;
        for(i = 0; i < s.size() && k < w.size(); i++) {
            
            if(s[i] != w[k][l]) return false;
            
            l++;
            
            if(l == w[k].size()) {
                k++;
                l = 0;
            }
        }
        if(i != s.size()) return false;
        return (l == 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1961.md" >}}
---
{{< youtube msS6F5DL8gQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1962: Remove Stones to Minimize the Total](https://grid47.xyz/posts/leetcode_1962) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

