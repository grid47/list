
+++
authors = ["Yasir"]
title = "Leetcode 22: Generate Parentheses"
date = "2024-10-07"
description = "Solution to Leetcode 22"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/generate-parentheses/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    void gen(string op, vector<string> &ans, int open, int closed, int n, int i) {
        if(i== 2*n) {
            ans.push_back(op);
            return;
        }
        
        if(open < n) {
            gen(op + "(", ans, open + 1, closed,n, i + 1);
        }
        if(open > closed) {
            gen(op + ")", ans, open, closed + 1,n, i + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen("", ans, 0, 0, n, 0);
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

