
+++
authors = ["Crafted by Me"]
title = "Leetcode 1828: Queries on Number of Points Inside a Circle"
date = "2019-11-01"
description = "In-depth solution and explanation for Leetcode 1828: Queries on Number of Points Inside a Circle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---
{{< youtube fU4oOBSsVMg >}}

"| 1829: Maximum XOR for Each Query |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

