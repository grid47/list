
+++
authors = ["grid47"]
title = "Leetcode 1512: Number of Good Pairs"
date = "2024-06-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1512: Number of Good Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "BqhDFUo1rjs"
youtube_upload_date="2023-10-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BqhDFUo1rjs/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> count;
        for (int a: A) {
            res += count[a]++;
        }
        return res;   
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1512.md" >}}
---
{{< youtube BqhDFUo1rjs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1513: Number of Substrings With Only 1s](https://grid47.xyz/leetcode/solution-1513-number-of-substrings-with-only-1s/) |
| --- |
