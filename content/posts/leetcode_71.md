
+++
authors = ["Crafted by Me"]
title = "Leetcode 71: Simplify Path"
date = "2024-08-22"
description = "Solution to Leetcode 71"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/simplify-path/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string simplifyPath(string path) {
        
        set<string> dot = {"..", ".", ""};
        
        string res = "", tmp;
        stringstream ss(path);
        
        stack<string> stk;
        
        while(getline(ss, tmp, '/')) {
            if(tmp == ".." && !stk.empty()) stk.pop();
            else if (!dot.count(tmp)) stk.push(tmp);
        }

        while(!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res == ""? "/": res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/71.md" >}}
---
{{< youtube 4e1gVeQ0AEs >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

