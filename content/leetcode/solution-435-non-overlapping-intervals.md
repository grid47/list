
+++
authors = ["grid47"]
title = "Leetcode 435: Non-overlapping Intervals"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 435: Non-overlapping Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/435.webp"
youtube = "mHsj83NoZDA"
youtube_upload_date="2023-07-20"
youtube_thumbnail="https://i.ytimg.com/vi/mHsj83NoZDA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/non-overlapping-intervals/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/435.webp" 
    alt="A sequence of intervals with non-overlapping sections glowing softly, showing the optimal arrangement."
    caption="Solution to LeetCode 435: Non-overlapping Intervals Problem"
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
    int eraseOverlapIntervals(vector<vector<int>>& ivl) {
        sort(ivl.begin(), ivl.end());
        int ans = 0;
        int n = ivl.size();
        int prv = 0;
        for(int cur = 1; cur < n; cur++) {
            // [1, 5]. [3, 6]
            // [2, 8]. [3, 5]
            if(ivl[cur][0] < ivl[prv][1]) {
                ans++;
                if(ivl[cur][1] <= ivl[prv][1])
                    prv = cur;
            } else {
                prv = cur;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/435.md" >}}
---
{{< youtube mHsj83NoZDA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #436: Find Right Interval](https://grid47.xyz/leetcode/solution-436-find-right-interval/) |
| --- |