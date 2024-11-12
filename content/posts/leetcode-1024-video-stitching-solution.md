
+++
authors = ["grid47"]
title = "Leetcode 1024: Video Stitching"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1024: Video Stitching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/video-stitching/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int res = 0;
        for(auto i = 0, st = 0, end = 0; st < time; st=end, ++res){
            for(; i < clips.size() && clips[i][0] <= st; ++i)
                end = max(end, clips[i][1]);
            if(st == end) return -1;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1024.md" >}}
---
{{< youtube 4Qho-im90ew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1026: Maximum Difference Between Node and Ancestor](https://grid47.xyz/posts/leetcode-1026-maximum-difference-between-node-and-ancestor-solution/) |
| --- |
