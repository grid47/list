
+++
authors = ["grid47"]
title = "Leetcode 856: Score of Parentheses"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 856: Score of Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/score-of-parentheses/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int scoreOfParentheses(string s) {
        int scr = 0;
        stack<int> stk;
        for(char &a : s) {
            if(a == '(') {
                stk.push(scr);
                scr = 0;
            }
            else {
                scr = stk.top() + max( 2 * scr, 1);
                stk.pop();
            }
        }
        return scr;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/856.md" >}}
---
{{< youtube iO0zA-N575k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #858: Mirror Reflection](https://grid47.xyz/posts/leetcode-858-mirror-reflection-solution/) |
| --- |
