
+++
authors = ["grid47"]
title = "Leetcode 48: Rotate Image"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 48: Rotate Image in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/48.webp"
youtube = "fMSJSS7eO1w"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fMSJSS7eO1w/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/rotate-image/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/48.webp" 
    alt="A serene, slow-moving image rotating in space, shifting with soft, calming colors."
    caption="Solution to LeetCode 48: Rotate Image Problem"
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
    void rotate(vector<vector<int>>& mtx) {
        int i = 0, j = mtx.size() - 1;
        while(i <= j)
            swap(mtx[i++], mtx[j--]);
        
        for(int i = 0; i < mtx.size(); i++)
        for(int j = i+1; j< mtx.size(); j++)
            swap(mtx[i][j], mtx[j][i]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/48.md" >}}
---
{{< youtube fMSJSS7eO1w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #49: Group Anagrams](https://grid47.xyz/leetcode/solution-49-group-anagrams/) |
| --- |