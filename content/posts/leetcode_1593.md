
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1593: Split a String Into the Max Number of Unique Substrings"
date = "2020-06-21"
description = "Solution to Leetcode 1593"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mx = 1, n;
    string s;
    
    int maxUniqueSplit(string s) {
        set<string> cnt;
        string tmp = "";
        n = s.size();
        this->s = s;
        bt(0, tmp, cnt);
        
        return mx;
    }
    
    void bt(int idx, string tmp, set<string> cnt) {
        if(idx == n) {
            mx = max(mx, (int)cnt.size());
            return;
        }
        
        for(int i = idx; i < n; i++) {
            tmp += s[i];
            if(!cnt.count(tmp)) {
                cnt.insert(tmp);
                bt(i + 1, "", cnt);
                cnt.erase(tmp);
            }
        }
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

