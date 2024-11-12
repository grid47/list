
+++
authors = ["grid47"]
title = "Leetcode 1541: Minimum Insertions to Balance a Parentheses String"
date = "2024-06-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1541: Minimum Insertions to Balance a Parentheses String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1541.md" >}}
---
{{< youtube PEKAlnmbBCc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1545: Find Kth Bit in Nth Binary String](https://grid47.xyz/posts/leetcode-1545-find-kth-bit-in-nth-binary-string-solution/) |
| --- |
