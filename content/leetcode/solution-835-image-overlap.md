
+++
authors = ["grid47"]
title = "Leetcode 835: Image Overlap"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 835: Image Overlap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zfjBapE3Y6E"
youtube_upload_date="2020-09-06"
youtube_thumbnail="https://i.ytimg.com/vi/zfjBapE3Y6E/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGCwgTih_MA8=&rs=AOn4CLDYXzk8BIj-n6f1vDE8kuCRNpZ81A"
+++



[`Problem Link`](https://leetcode.com/problems/image-overlap/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> la, lb;
        int n = img1.size();
        for(int i = 0; i < n*n; i++)
            if(img1[i/n][i%n] == 1)
            la.push_back(i/n*100+ i%n);
        for(int i = 0; i < n*n; i++)
            if(img2[i/n][i%n] == 1)
            lb.push_back(i/n*100+ i%n);
        unordered_map<int, int> mp;
        for(int i : la)
        for(int j : lb)
            mp[i-j]++;
        int res = 0;
        for(auto it: mp)
        res = max(res, it.second);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/835.md" >}}
---
{{< youtube zfjBapE3Y6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #836: Rectangle Overlap](https://grid47.xyz/leetcode/solution-836-rectangle-overlap/) |
| --- |
