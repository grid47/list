
+++
authors = ["Yasir"]
title = "Leetcode 856: Score of Parentheses"
date = "2022-06-25"
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

{{< highlight html >}}
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

