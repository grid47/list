
+++
authors = ["Crafted by Me"]
title = "Leetcode 859: Buddy Strings"
date = "2022-06-26"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/859.md" >}}
---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

