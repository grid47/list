
+++
authors = ["Yasir"]
title = "Leetcode 452: Minimum Number of Arrows to Burst Balloons"
date = "2023-08-04"
description = "Solution to Leetcode 452"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& pts) {
        sort(pts.begin(), pts.end(), cmp);
        int cnt = 1, arp = pts[0][1];
        for(int i = 1; i < pts.size(); i++) {
            
            if(pts[i][0]<=arp) continue;
            cnt++;
            arp = pts[i][1];
        }
        return cnt;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

