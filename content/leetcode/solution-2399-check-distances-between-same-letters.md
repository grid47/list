
+++
authors = ["grid47"]
title = "Leetcode 2399: Check Distances Between Same Letters"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2399: Check Distances Between Same Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "uNv8XvliP0o"
youtube_upload_date="2022-09-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uNv8XvliP0o/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/check-distances-between-same-letters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  bool checkDistances(string s, vector<int>& distance) {
    int pos[26] = {};
    for (int i = 0; i < s.size(); ++i) {
        int n = s[i] - 'a';
        if (pos[n] > 0 && distance[n] != i - pos[n])
            return false;
        pos[n] = i + 1;
    }
    return true;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2399.md" >}}
---
{{< youtube uNv8XvliP0o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2400: Number of Ways to Reach a Position After Exactly k Steps](https://grid47.xyz/leetcode/solution-2400-number-of-ways-to-reach-a-position-after-exactly-k-steps/) |
| --- |