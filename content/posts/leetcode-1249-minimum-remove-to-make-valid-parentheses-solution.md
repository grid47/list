
+++
authors = ["grid47"]
title = "Leetcode 1249: Minimum Remove to Make Valid Parentheses"
date = "2024-07-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1249: Minimum Remove to Make Valid Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stk, itk;
        for(int i = 0; i < s.length(); i++) {
            char a = s[i];
                 if(a == '(') { stk.push_back(i); }
            else if(a == ')') {
                     if(stk.size()    == 0)    stk.push_back(i);
                else if(s[stk.back()] == '(')  stk.pop_back();
                else stk.push_back(i);
            }
        }
        string res = "";
        set<int> st(stk.begin(), stk.end());
        for(int i = 0; i < s.length(); i++) {
            if(st.count(i)) continue;
            res += s[i];
        }
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1249.md" >}}
---
{{< youtube tMzZUDR_cH0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1253: Reconstruct a 2-Row Binary Matrix](https://grid47.xyz/posts/leetcode-1253-reconstruct-a-2-row-binary-matrix-solution/) |
| --- |
