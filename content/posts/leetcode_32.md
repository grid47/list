
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 32: Longest Valid Parentheses"
date = "2024-09-27"
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

{{< highlight cpp >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

