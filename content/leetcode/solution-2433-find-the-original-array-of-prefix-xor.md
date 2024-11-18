
+++
authors = ["grid47"]
title = "Leetcode 2433: Find The Original Array of Prefix Xor"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2433: Find The Original Array of Prefix Xor in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "idcT-p_DDrI"
youtube_upload_date="2023-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/idcT-p_DDrI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size());
        res[0] = pref[0];
        for(int i = 1; i < pref.size(); i++)
            res[i] = pref[i] ^ pref[i - 1];
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2433.md" >}}
---
{{< youtube idcT-p_DDrI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2434: Using a Robot to Print the Lexicographically Smallest String](https://grid47.xyz/leetcode/solution-2434-using-a-robot-to-print-the-lexicographically-smallest-string/) |
| --- |
