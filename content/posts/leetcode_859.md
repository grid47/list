
+++
authors = ["Yasir"]
title = "Leetcode 859: Buddy Strings"
date = "2022-06-22"
description = "Solution to Leetcode 859"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/buddy-strings/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int cnt = 0, fst = -1, scd = -1, cl = 0, fg = 0, t = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != goal[i]) {
                cnt++;
                if(fst == -1) fst = i;
                else if(scd == -1) scd = i;
            }
            if((fg >> (s[i] - 'a')) & 1) t = 1;
            fg |= (1 << (s[i] - 'a'));
        }
        
        if(cnt == 0) {
            if(t) return true;
            return false;
        }

        return (cnt == 2 && (s[fst] == goal[scd]) && (s[scd] == goal[fst]));
    }
};
{{< /highlight >}}

