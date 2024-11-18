
+++
authors = ["grid47"]
title = "Leetcode 2374: Node With Highest Edge Score"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2374: Node With Highest Edge Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "1egOQhIT9Gg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/node-with-highest-edge-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int, long long> mp;
        int n = edges.size();
        int mx = -1, idx = -1;
        for(int i = 0; i < n; i++) {
            mp[edges[i]] += i;
            if(mp[edges[i]] > mx) {
                idx = edges[i];
                mx = mp[edges[i]];
            } else if(mp[edges[i]] == mx) {
                if(edges[i] < idx)
                    idx = edges[i];
            }
        }
        return idx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2374.md" >}}
---
{{< youtube 1egOQhIT9Gg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2375: Construct Smallest Number From DI String](https://grid47.xyz/leetcode/solution-2375-construct-smallest-number-from-di-string/) |
| --- |
