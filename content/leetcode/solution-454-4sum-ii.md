
+++
authors = ["grid47"]
title = "Leetcode 454: 4Sum II"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 454: 4Sum II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/454.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/4sum-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/454.webp" 
    alt="A sequence of quadruples where each valid sum is softly highlighted to show the results."
    caption="Solution to LeetCode 454: 4Sum II Problem"
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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int a : A)
        for(int b : B)
        mp[a+b]++;
        for(int c : C)
        for(int d : D)
        if(mp.count(-c-d)) res+= mp[-c-d];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/454.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #455: Assign Cookies](https://grid47.xyz/leetcode/solution-455-assign-cookies/) |
| --- |