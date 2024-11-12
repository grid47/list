
+++
authors = ["grid47"]
title = "Leetcode 150: Evaluate Reverse Polish Notation"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 150: Evaluate Reverse Polish Notation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/150.webp" 
    alt="A glowing stack of numbers, gently unfolding and calculating the final result step-by-step."
    caption="Solution to LeetCode 150: Evaluate Reverse Polish Notation Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #152: Maximum Product Subarray](https://grid47.xyz/posts/leetcode-152-maximum-product-subarray-solution/) |
| --- |
