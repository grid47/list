
+++
authors = ["Crafted by Me"]
title = "Leetcode 67: Add Binary"
date = "2024-08-27"
description = "Solution to Leetcode 67"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-binary/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string addBinary(string a, string b) {
        
        int cr = 0;
        string res = "";
        while(!a.empty() || !b.empty() || cr) {
            if(!a.empty()) {
                cr += a.back() - '0';
                a.pop_back();
            }
            if(!b.empty()) {
                cr += b.back() - '0';
                b.pop_back();
            }
            
            res = to_string(cr % 2) + res;
            cr /= 2;
        }
        return res;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/67.md" >}}
- by gpt
        
---
{{< youtube M9foA9gcL98 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

