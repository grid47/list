
+++
authors = ["Yasir"]
title = "Leetcode 1003: Check If Word Is Valid After Substitutions"
date = "2022-01-29"
description = "Solution to Leetcode 1003"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for(char c : s) {
            if(c == 'c') {
                int n = stk.size();
                if(n < 2 ||
                  stk[n - 1] != 'b' ||
                  stk[n - 2] != 'a' ) 
                    return false;
                stk.pop_back();
                stk.pop_back();
            } else stk.push_back(c);
        }
        
        return stk.size() == 0;
    }
};
{{< /highlight >}}

