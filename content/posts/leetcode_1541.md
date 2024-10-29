
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1541: Minimum Insertions to Balance a Parentheses String"
date = "2020-08-11"
description = "Solution to Leetcode 1541"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        
        int n = s.size();
        
        stack<char> stk;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push('(');
                continue;
            }
            
            if(i + 1 < n && s[i + 1] == ')') {
                if(!stk.empty()) stk.pop();
                else res++;
                i++;
            } else {
                if(!stk.empty()) {stk.pop(); res++;}
                else res += 2;
            }
            
        }
        
        return res + stk.size() * 2;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

