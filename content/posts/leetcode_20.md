
+++
authors = ["Crafted by Me"]
title = "Leetcode 20: Valid Parentheses"
date = "2024-10-13"
description = "Solution to Leetcode 20"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-parentheses/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char x: s) {
            if(x == '(' || x == '{' || x == '[') {
                stk.push(x);
            } else {
                     if(x == ')' && !stk.empty() && stk.top() == '(') stk.pop();
                else if(x == '}' && !stk.empty() && stk.top() == '{') stk.pop();
                else if(x == ']' && !stk.empty() && stk.top() == '[') stk.pop();                
                else return false;
            }
        }
        return stk.empty();
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/20.md" >}}
- by gpt
        
---
{{< youtube WTzjTskDFMg >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

