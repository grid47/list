
+++
authors = ["Crafted by Me"]
title = "Leetcode 921: Minimum Add to Make Parentheses Valid"
date = "2022-04-26"
description = "In-depth solution and explanation for Leetcode 921: Minimum Add to Make Parentheses Valid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube EPr9X0Y3vmo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #922: Sort Array By Parity II](https://grid47.xyz/posts/leetcode_922) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

