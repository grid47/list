
+++
authors = ["grid47"]
title = "Leetcode 2211: Count Collisions on a Road"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2211: Count Collisions on a Road in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-collisions-on-a-road/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCollisions(string dir) {
        int l = 0, r = dir.size() - 1;
        int n = dir.size();
        while(l < n && dir[l] == 'L')
            l++;
        
        while(r >= 0 && dir[r] == 'R')
            r--;
        
        int cnt = 0;
        for(int i = l; i <= r; i++)
            if(dir[i] != 'S')
                cnt++;
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2211.md" >}}
---
{{< youtube Cy_E7rABX_U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2212: Maximum Points in an Archery Competition](https://grid47.xyz/posts/leetcode-2212-maximum-points-in-an-archery-competition-solution/) |
| --- |
