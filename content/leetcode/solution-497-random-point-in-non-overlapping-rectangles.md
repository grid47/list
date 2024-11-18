
+++
authors = ["grid47"]
title = "Leetcode 497: Random Point in Non-overlapping Rectangles"
date = "2024-09-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 497: Random Point in Non-overlapping Rectangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Reservoir Sampling","Prefix Sum","Ordered Set","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/497.webp"
youtube = "8kwPXbTMSnk"
youtube_upload_date="2020-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/8kwPXbTMSnk/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGHIgZCgaMA8=&rs=AOn4CLAFskjPMvHmINXyYhzAGRh0xLe3Fw"
+++



[`Problem Link`](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/497.webp" 
    alt="A series of non-overlapping rectangles where random points are chosen and softly illuminated as they are selected."
    caption="Solution to LeetCode 497: Random Point in Non-overlapping Rectangles Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> v;
    vector<vector<int>> rect;
public:
    
    int area(vector<int> r) {
        
        return (r[2] - r[0] +1) * (r[3] - r[1] +1);
    }
    
    Solution(vector<vector<int>>& r) {
        rect = r;
        for(vector<int> re : r) {
            v.push_back(area(re) + (v.empty()? 0 : v.back()));
        }
    }
    
    vector<int> pick() {
        int d = rand() % v.back();
        int idz = upper_bound(v.begin(), v.end(), d) - v.begin();
        vector<int> r = rect[idz];
        return {
            rand() % (r[2] - r[0] +1) + r[0],
            rand() % (r[3] - r[1] +1) + r[1]
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/497.md" >}}
---
{{< youtube 8kwPXbTMSnk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #498: Diagonal Traverse](https://grid47.xyz/leetcode/solution-498-diagonal-traverse/) |
| --- |
