
+++
authors = ["grid47"]
title = "Leetcode 1190: Reverse Substrings Between Each Pair of Parentheses"
date = "2024-07-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1190: Reverse Substrings Between Each Pair of Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
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
{{< youtube n_pCJmg-RyU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1195: Fizz Buzz Multithreaded](https://grid47.xyz/posts/leetcode-1195-fizz-buzz-multithreaded-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
