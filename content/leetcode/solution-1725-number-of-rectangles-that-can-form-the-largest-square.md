
+++
authors = ["grid47"]
title = "Leetcode 1725: Number Of Rectangles That Can Form The Largest Square"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1725: Number Of Rectangles That Can Form The Largest Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ajl13jUxfdM"
youtube_upload_date="2021-01-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ajl13jUxfdM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto i:rectangles){
            int m=min(i[0],i[1]);
            ans=max(ans,m);
            mp[m]++;
        }
        
        return mp[ans];

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1725.md" >}}
---
{{< youtube ajl13jUxfdM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1726: Tuple with Same Product](https://grid47.xyz/leetcode/solution-1726-tuple-with-same-product/) |
| --- |
