
+++
authors = ["grid47"]
title = "Leetcode 2271: Maximum White Tiles Covered by a Carpet"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2271: Maximum White Tiles Covered by a Carpet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "U7fqZr_ZLd4"
youtube_upload_date="2022-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/U7fqZr_ZLd4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len) {
        
        int n = t.size(), res = 0,
            cover = 0, j = 0, partial = 0;

        sort(t.begin(), t.end());
        
        for(int i = 0; i < n && res < len ; ) {
            if(t[j][0] + len > t[i][1]) {
                cover += t[i][1] - t[i][0] + 1;
                res = max(res, cover);               
                i++;
            } else {
                partial = max(0, t[j][0] + len - t[i][0]);
                res = max(res, cover + partial);
                cover -= (t[j][1] - t[j][0] + 1);
                j++;
            }            
        }
        
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2271.md" >}}
---
{{< youtube U7fqZr_ZLd4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2273: Find Resultant Array After Removing Anagrams](https://grid47.xyz/leetcode/solution-2273-find-resultant-array-after-removing-anagrams/) |
| --- |
