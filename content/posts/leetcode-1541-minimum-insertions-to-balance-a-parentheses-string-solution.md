
+++
authors = ["grid47"]
title = "Leetcode 1541: Minimum Insertions to Balance a Parentheses String"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1542: Find Longest Awesome Substring](https://grid47.xyz/posts/leetcode-1542-find-longest-awesome-substring-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
