
+++
authors = ["grid47"]
title = "Leetcode 678: Valid Parenthesis String"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 678: Valid Parenthesis String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-parenthesis-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stk, str;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*')
                str.push(i);
            else if(s[i] == '(')
                stk.push(i);
            else {
                if(!stk.empty())
                stk.pop();
                else if(!str.empty()) str.pop();
                else return false;
            }
        }
        while(!stk.empty() && !str.empty() && stk.top() < str.top()) {
            str.pop();
            stk.pop();
        }

        return stk.empty();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/678.md" >}}
---
{{< youtube QhPdNS143Qg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #684: Redundant Connection](https://grid47.xyz/posts/leetcode-684-redundant-connection-solution/) |
| --- |
