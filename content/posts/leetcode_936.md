
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 936: Stamping The Sequence"
date = "2022-04-09"
description = "Solution to Leetcode 936"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stamping-the-sequence/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        
        int turns = -1, net = 0;
        while(turns) {
            turns = 0;
            for(int sz = stamp.size(); sz > 0; sz--) {
                for(int i = 0; i <= stamp.size() - sz; i++) {
                    string key = string(i, '*') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
                    auto pos = target.find(key);
                    while(pos != string::npos) {
                        res.push_back(pos);
                        turns += sz;
                        fill(target.begin() + pos, target.begin() + pos + stamp.size(), '*');
                        pos = target.find(key);
                    }
                }
            }
            // cout << turns << " ";
            net += turns;
        }

        reverse(res.begin(), res.end());
        return net == target.size()? res: vector<int>{};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/936.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

