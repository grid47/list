
+++
authors = ["Crafted by Me"]
title = "Leetcode 678: Valid Parenthesis String"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #679: 24 Game](https://grid47.xyz/posts/leetcode_679) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
