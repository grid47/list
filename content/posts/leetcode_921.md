
+++
authors = ["Crafted by Me"]
title = "Leetcode 921: Minimum Add to Make Parentheses Valid"
date = "2022-04-26"
description = "Solution to Leetcode 921"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        stack<int> stk;
        for(char &a : s) {
            if(a == '(') {
                stk.push(a);
            } else {
                if(stk.empty()) {
                    res++;
                } else {
                    stk.pop();
                }
            }
        }
        
        res += stk.size();
        return res;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/921.md" >}}
- by gpt
        
---
{{< youtube EPr9X0Y3vmo >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

