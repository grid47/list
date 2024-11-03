
+++
authors = ["Crafted by Me"]
title = "Leetcode 1190: Reverse Substrings Between Each Pair of Parentheses"
date = "2021-07-31"
description = "In-depth solution and explanation for Leetcode 1190: Reverse Substrings Between Each Pair of Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string res;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') 
                stk.push(res.size());
            else if(s[i] == ')') {
                int j = stk.top();
                stk.pop();
                reverse(res.begin() + j, res.end());
            } else res.push_back(s[i]);
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1190.md" >}}
---


"| 1191: K-Concatenation Maximum Sum |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

