
+++
authors = ["Crafted by Me"]
title = "Leetcode 1042: Flower Planting With No Adjacent"
date = "2021-12-25"
description = "Solution to Leetcode 1042"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flower-planting-with-no-adjacent/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> res(n, 0);
        vector<vector<int>> gph(n);
        for(vector<int> &p: paths) {
            gph[p[0]-1].push_back(p[1]-1);
            gph[p[1]-1].push_back(p[0]-1);
        }
        for(int i = 0; i < n; i++) {
            int colors[5] = {};
            for(int j: gph[i]) {
                colors[res[j]] = 1;
            }
            for(int c = 4; c > 0; c--)
                if(!colors[c])
                    res[i] = c;
            
        }
        return res;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

