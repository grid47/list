
+++
authors = ["Yasir"]
title = "Leetcode 763: Partition Labels"
date = "2022-09-25"
description = "Solution to Leetcode 763"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-labels/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        
        vector<int> res;
        int prv = -1, mx = mp[s[0]];
        for(int i = 0; i < s.size(); i++) {
            mx = max(mx, mp[s[i]]);
            if(i == mx || i == s.size() - 1) {
                res.push_back(i - prv);
                prv = mx;
            }
        }
        return res;
    }
};
{{< /highlight >}}

