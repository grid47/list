
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 205: Isomorphic Strings"
date = "2024-04-07"
description = "Solution to Leetcode 205"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/isomorphic-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isIsomorphic(string s, string t) {
       
         
        map<char, char> fwd, rwd;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if (fwd.count(s[i])){
                if(fwd[s[i]] != t[i])
                    return false;
            }
            if(rwd.count(t[i])){
                if(rwd[t[i]] != s[i])
                    return false;
            }
            fwd[s[i]] = t[i];
            rwd[t[i]] = s[i];
        }
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

