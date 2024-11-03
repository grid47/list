
+++
authors = ["Crafted by Me"]
title = "Leetcode 32: Longest Valid Parentheses"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 32: Longest Valid Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/32.md" >}}
---
{{< youtube CPEDLKfaQJE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #33: Search in Rotated Sorted Array](https://grid47.xyz/posts/leetcode_33) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

