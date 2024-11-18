
+++
authors = ["grid47"]
title = "Leetcode 2580: Count Ways to Group Overlapping Ranges"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2580: Count Ways to Group Overlapping Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "5-8-2mDdoGs"
youtube_upload_date="2023-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/5-8-2mDdoGs/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countWays(vector<vector<int>>& range) {
        sort(range.begin(), range.end());
        int n = range.size();
        
        int mod = (int) 1e9 + 7;        
        int next = range[0][1];
        long cnt = 2;
        for(int i = 0; i < n; i++) {
            if(range[i][0] <= next) {
                next = max(next, range[i][1]);
                continue;
            }
            cnt = (cnt * 2) % mod;
            next = range[i][1];
        }

        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2580.md" >}}
---
{{< youtube 5-8-2mDdoGs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2582: Pass the Pillow](https://grid47.xyz/leetcode/solution-2582-pass-the-pillow/) |
| --- |
