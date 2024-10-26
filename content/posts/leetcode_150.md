
+++
authors = ["Yasir"]
title = "Leetcode 150: Evaluate Reverse Polish Notation"
date = "2024-05-30"
description = "Solution to Leetcode 150"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for(int i = 0; i < n; i++) {
            if(tokens[i] != "+" &&
               tokens[i] != "-" &&
               tokens[i] != "*" &&
               tokens[i] != "/") {
                stk.push(stoi(tokens[i]));
            } else {
                int x = stk.top(); stk.pop();
                int y = stk.top(); stk.pop();
                
                    if(tokens[i] == "*"){ stk.push(y * x); }
                    if(tokens[i] == "/"){ stk.push(y / x); }
                    if(tokens[i] == "+"){ stk.push(y + x); }
                    if(tokens[i] == "-"){ stk.push(y - x); }
                
            }
        }
        return stk.top();
    }
};
{{< /highlight >}}

