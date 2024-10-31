
+++
authors = ["Crafted by Me"]
title = "Leetcode 447: Number of Boomerangs"
date = "2023-08-12"
description = "Solution to Leetcode 447"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-boomerangs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        map<int, int> mp;
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            for(int j = 0; j < points.size(); j++) {
                int d = getDist(points[i], points[j]);
                mp[d]++;
            }
            for(auto [_, val]: mp)
            res += val * (val - 1);
            mp.clear();
        }
        return res;
    }

    int getDist(vector<int> a, vector<int> b) {
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        return x * x + y * y;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/447.md" >}}
---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

