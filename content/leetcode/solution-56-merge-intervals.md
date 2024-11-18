
+++
authors = ["grid47"]
title = "Leetcode 56: Merge Intervals"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 56: Merge Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/56.webp"
youtube = "HCbKvBOlMVI"
youtube_upload_date="2024-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/HCbKvBOlMVI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/merge-intervals/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/56.webp" 
    alt="Multiple flowing light intervals coming together and merging in perfect harmony."
    caption="Solution to LeetCode 56: Merge Intervals Problem"
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
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        sort(iv.begin(), iv.end());
        vector<vector<int>> ans;
        vector<int> tmp = iv[0];
        for(int i = 0; i < iv.size(); i++) {
            if(iv[i][0] <= tmp[1]) {
                tmp[1] = max(tmp[1], iv[i][1]);
            } else {
                ans.push_back(tmp);
                tmp = iv[i];
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/56.md" >}}
---
{{< youtube HCbKvBOlMVI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #57: Insert Interval](https://grid47.xyz/leetcode/solution-57-insert-interval/) |
| --- |
