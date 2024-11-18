
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
img_src = ""
youtube = "--wKPR3ByJc"
youtube_upload_date="2024-07-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/--wKPR3ByJc/maxresdefault.webp"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1337: The K Weakest Rows in a Matrix](https://grid47.xyz/leetcode/solution-1337-the-k-weakest-rows-in-a-matrix/) |
| --- |
