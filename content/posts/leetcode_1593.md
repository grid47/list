
+++
authors = ["Yasir"]
title = "Leetcode 1593: Split a String Into the Max Number of Unique Substrings"
date = "2020-06-18"
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

**Code:**

{{< highlight html >}}
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

