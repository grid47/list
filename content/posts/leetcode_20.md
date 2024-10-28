
+++
authors = ["Yasir"]
title = "Leetcode 20: Valid Parentheses"
date = "2024-10-09"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

