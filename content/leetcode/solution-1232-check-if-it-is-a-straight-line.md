
+++
authors = ["grid47"]
title = "Leetcode 1232: Check If It Is a Straight Line"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1232: Check If It Is a Straight Line in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-it-is-a-straight-line/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cord) {
        double slopt = (cord[1][0] - cord[0][0]) == 0? INT_MAX: (double)(cord[1][1] - cord[0][1]) / (double)(cord[1][0] - cord[0][0]);
        for(int i = 2; i < cord.size(); i++) {
            double slp = (cord[i][0] - cord[0][0]) == 0?INT_MAX: (double)(cord[i][1] - cord[0][1]) / (double)(cord[i][0] - cord[0][0]);
            if(slp != slopt) return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1232.md" >}}
---
{{< youtube _tfiTQNZCbs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1233: Remove Sub-Folders from the Filesystem](https://grid47.xyz/leetcode/solution-1233-remove-sub-folders-from-the-filesystem/) |
| --- |
