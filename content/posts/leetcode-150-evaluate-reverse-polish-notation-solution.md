
+++
authors = ["grid47"]
title = "Leetcode 150: Evaluate Reverse Polish Notation"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 150: Evaluate Reverse Polish Notation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/150.md" >}}
---
{{< youtube ffgmKxRqiMc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #152: Maximum Product Subarray](https://grid47.xyz/posts/leetcode-152-maximum-product-subarray-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
