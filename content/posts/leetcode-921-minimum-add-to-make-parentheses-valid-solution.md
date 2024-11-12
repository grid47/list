
+++
authors = ["grid47"]
title = "Leetcode 921: Minimum Add to Make Parentheses Valid"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 921: Minimum Add to Make Parentheses Valid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/921.md" >}}
---
{{< youtube EPr9X0Y3vmo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #925: Long Pressed Name](https://grid47.xyz/posts/leetcode-925-long-pressed-name-solution/) |
| --- |
