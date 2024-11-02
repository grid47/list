
+++
authors = ["Crafted by Me"]
title = "Leetcode 678: Valid Parenthesis String"
date = "2021-12-24"
description = "Solution to Leetcode 678"
tags = [
    
]
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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

