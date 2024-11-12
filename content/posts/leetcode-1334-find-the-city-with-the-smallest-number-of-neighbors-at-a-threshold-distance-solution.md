
+++
authors = ["grid47"]
title = "Leetcode 1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Graph","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& eds, int thd) {
        vector<vector<int>> d(n, vector (n, 10001));
        for(vector<int> &e: eds) {
d[e[0]][e[1]] = d[e[1]][e[0]] = e[2];
}
        for(int i = 0; i < n; i++)
{ d[i][i] = 0; }
        
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
        
        int sm = n +1, res = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0 ; j < n; j++) {
                if(d[i][j] <= thd) {
                    cnt++;
                    }
            }
            
            if (cnt <= sm) {
                res = i;
                sm = cnt;
            }
            
        }
        
        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1334.md" >}}
---
{{< youtube --wKPR3ByJc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1335: Minimum Difficulty of a Job Schedule](https://grid47.xyz/posts/leetcode-1335-minimum-difficulty-of-a-job-schedule-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
