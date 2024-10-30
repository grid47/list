
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1849: Splitting a String Into Descending Consecutive Values"
date = "2019-10-09"
description = "Solution to Leetcode 1849"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/)

---
{{< youtube eDtMmysldaw >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s;
    bool splitString(string s) {
        this->s = s;
        double tmp = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            tmp = tmp * 10 + (s[i] - '0');
            if(bt(i + 1, tmp)) return true;
        }
        return false;
    }
    
    bool bt(int idx, double prv) {

        if(idx == s.size()) return true;
        
        double tmp = 0;
        for(int i = idx; i < s.size(); i++) {
            tmp = tmp * 10 + (s[i] - '0');
            if(tmp - prv > -1) break;
            if(tmp - prv == -1) {
                if(bt(i + 1, tmp))
                    return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

