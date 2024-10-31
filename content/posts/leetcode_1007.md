
+++
authors = ["Crafted by Me"]
title = "Leetcode 1007: Minimum Domino Rotations For Equal Row"
date = "2022-01-29"
description = "Solution to Leetcode 1007"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        map<int, int> mp;
        vector<int> tc(7, 0), uc(7, 0);
        int n = top.size();
        for(int i = 0; i < n; i++) {
            if(bottom[i] != top[i]) {
                mp[bottom[i]]++;
                mp[top[i]]++;
            } else mp[top[i]]++;

            uc[bottom[i]]++;
            tc[top[i]]++;
        }
        
        vector<int> opt;
        for(auto it: mp) {
            if(it.second == n)
                opt.push_back(it.first);
        }
        if(opt.empty()) return -1;
        
        int res = INT_MAX;
        for(int x: opt) {
            if(uc[x] == n || tc[x] == n) return 0;
            res = min(res, n - uc[x]);
            res = min(res, n - tc[x]);
        }
        return res;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

