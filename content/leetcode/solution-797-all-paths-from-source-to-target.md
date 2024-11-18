
+++
authors = ["grid47"]
title = "Leetcode 797: All Paths From Source to Target"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 797: All Paths From Source to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/797.webp"
youtube = "MQU2IIWwaOg"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/MQU2IIWwaOg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/all-paths-from-source-to-target/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/797.webp" 
    alt="A graph where all paths are traced from source to target, with each path softly glowing as it is found."
    caption="Solution to LeetCode 797: All Paths From Source to Target Problem"
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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});
        while(!q.empty()) {
            int x = q.front().first;
            vector<int> t = q.front().second;
            q.pop();
            if(x == graph.size() - 1) ans.push_back(t);
            for(int k: graph[x]) {
                t.push_back(k);
                q.push({k, t});
                t.pop_back();
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/797.md" >}}
---
{{< youtube MQU2IIWwaOg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #799: Champagne Tower](https://grid47.xyz/leetcode/solution-799-champagne-tower/) |
| --- |
