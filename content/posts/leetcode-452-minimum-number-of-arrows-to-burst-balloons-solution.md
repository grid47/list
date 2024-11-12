
+++
authors = ["grid47"]
title = "Leetcode 452: Minimum Number of Arrows to Burst Balloons"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 452: Minimum Number of Arrows to Burst Balloons in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/452.webp" 
    alt="A sequence of balloons gently bursting with each arrow, showing the optimal number of arrows needed."
    caption="Solution to LeetCode 452: Minimum Number of Arrows to Burst Balloons Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/452.md" >}}
---
{{< youtube lPmkKnvNPrw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #454: 4Sum II](https://grid47.xyz/posts/leetcode-454-4sum-ii-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
