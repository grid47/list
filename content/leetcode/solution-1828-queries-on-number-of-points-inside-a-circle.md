
+++
authors = ["grid47"]
title = "Leetcode 1828: Queries on Number of Points Inside a Circle"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1828: Queries on Number of Points Inside a Circle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fU4oOBSsVMg"
youtube_upload_date="2021-04-19"
youtube_thumbnail="https://i.ytimg.com/vi/fU4oOBSsVMg/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1828.md" >}}
---
{{< youtube fU4oOBSsVMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1829: Maximum XOR for Each Query](https://grid47.xyz/leetcode/solution-1829-maximum-xor-for-each-query/) |
| --- |