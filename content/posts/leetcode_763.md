
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 763: Partition Labels"
date = "2022-09-29"
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
{{< youtube B7m8UmZE-vw >}}
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/763.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

