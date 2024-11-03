
+++
authors = ["Crafted by Me"]
title = "Leetcode 20: Valid Parentheses"
date = "2024-10-13"
description = "In-depth solution and explanation for Leetcode 20: Valid Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube WTzjTskDFMg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #21: Merge Two Sorted Lists](https://grid47.xyz/posts/leetcode_21) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

