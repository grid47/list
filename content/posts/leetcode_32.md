
+++
authors = ["Yasir"]
title = "Leetcode 32: Longest Valid Parentheses"
date = "2024-09-23"
description = "Solution to Leetcode 32"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-valid-parentheses/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxL = 0;
        for(int i=0;i<s.size();i++)
        {
            int t = stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
    }
};
{{< /highlight >}}

