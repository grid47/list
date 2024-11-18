
+++
authors = ["grid47"]
title = "Leetcode 898: Bitwise ORs of Subarrays"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 898: Bitwise ORs of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/bitwise-ors-of-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur, cur2;

        for(int x : arr) {
            cur2 = { x };
            for(int i : cur)        cur2.insert(i | x);
            for(int j : cur = cur2)  res.insert(j);
        }

        return res.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/898.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #900: RLE Iterator](https://grid47.xyz/leetcode/solution-900-rle-iterator/) |
| --- |
