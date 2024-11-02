
+++
authors = ["Crafted by Me"]
title = "Leetcode 856: Score of Parentheses"
date = "2021-06-29"
description = "Solution to Leetcode 856"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/score-of-parentheses/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int scoreOfParentheses(string s) {
        int scr = 0;
        stack<int> stk;
        for(char &a : s) {
            if(a == '(') {
                stk.push(scr);
                scr = 0;
            }
            else {
                scr = stk.top() + max( 2 * scr, 1);
                stk.pop();
            }
        }
        return scr;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/856.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

