
+++
authors = ["Crafted by Me"]
title = "Leetcode 1190: Reverse Substrings Between Each Pair of Parentheses"
date = "2020-07-30"
description = "Solution to Leetcode 1190"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

