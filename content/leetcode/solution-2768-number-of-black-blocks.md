
+++
authors = ["grid47"]
title = "Leetcode 2768: Number of Black Blocks"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2768: Number of Black Blocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qnbzbMmLK8Q"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/qnbzbMmLK8Q/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-black-blocks/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> cnt;
        vector<long long> res = {(n - 1L) * (m - 1), 0, 0, 0, 0};
        for (auto& c: coordinates)
            for (int i = c[0]; i < c[0] + 2; ++i)
                for (int j = c[1]; j < c[1] + 2; ++j)
                    if (0 < i && i < m && 0 < j && j < n) {
                        res[cnt[i * 100000L + j]]--;
                        cnt[i * 100000L + j]++;
                        res[cnt[i * 100000L + j]]++;
                    }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2768.md" >}}
---
{{< youtube qnbzbMmLK8Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2769: Find the Maximum Achievable Number](https://grid47.xyz/leetcode/solution-2769-find-the-maximum-achievable-number/) |
| --- |