
+++
authors = ["grid47"]
title = "Leetcode 997: Find the Town Judge"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 997: Find the Town Judge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Graph"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "xR2Qg9ENtKQ"
youtube_upload_date="2020-05-10"
youtube_thumbnail="https://i.ytimg.com/vi/xR2Qg9ENtKQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-town-judge/description/)

---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg(n + 1, 0);
        for(auto x: trust) {
            deg[x[1]]++;
            deg[x[0]]--;
        }
        for(int i = 1; i <= n; i++)
            if(deg[i] == n - 1) return i;
        
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/997.md" >}}
---
{{< youtube xR2Qg9ENtKQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #998: Maximum Binary Tree II](https://grid47.xyz/leetcode/solution-998-maximum-binary-tree-ii/) |
| --- |
