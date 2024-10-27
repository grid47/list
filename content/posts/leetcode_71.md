
+++
authors = ["Yasir"]
title = "Leetcode 71: Simplify Path"
date = "2024-08-18"
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

{{< highlight html >}}
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

