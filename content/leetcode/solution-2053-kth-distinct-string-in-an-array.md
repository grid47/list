
+++
authors = ["grid47"]
title = "Leetcode 2053: Kth Distinct String in an Array"
date = "2024-04-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2053: Kth Distinct String in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "1KOnvGPv9Mo"
youtube_upload_date="2024-08-05"
youtube_thumbnail="https://i.ytimg.com/vi/1KOnvGPv9Mo/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/kth-distinct-string-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto &s : arr)
            ++mp[s];
        for (auto &s : arr)
            if (mp[s] == 1 && --k == 0)
                return s;
        return "";
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2053.md" >}}
---
{{< youtube 1KOnvGPv9Mo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2054: Two Best Non-Overlapping Events](https://grid47.xyz/leetcode/solution-2054-two-best-non-overlapping-events/) |
| --- |