
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1828: Queries on Number of Points Inside a Circle"
date = "2019-10-28"
description = "Solution to Leetcode 1828"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    typedef vector<vector<int>> mo;
public:
    vector<int> countPoints(mo& pts, mo& qrs) {
        vector<int> res;

        for(auto &q: qrs) {
            int cnt = 0, rr = q[2] * q[2];
            for(auto &p: pts)
                cnt += (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]) <= rr;
            res.push_back(cnt);
        }

        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

