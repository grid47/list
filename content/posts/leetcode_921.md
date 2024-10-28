
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 921: Minimum Add to Make Parentheses Valid"
date = "2022-04-22"
description = "Solution to Leetcode 921"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        stack<int> stk;
        for(char &a : s) {
            if(a == '(') {
                stk.push(a);
            } else {
                if(stk.empty()) {
                    res++;
                } else {
                    stk.pop();
                }
            }
        }
        
        res += stk.size();
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

