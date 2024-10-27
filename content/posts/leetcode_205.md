
+++
authors = ["Yasir"]
title = "Leetcode 205: Isomorphic Strings"
date = "2024-04-06"
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

{{< highlight html >}}
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

