
+++
authors = ["grid47"]
title = "Leetcode 1218: Longest Arithmetic Subsequence of Given Difference"
date = "2024-07-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1218: Longest Arithmetic Subsequence of Given Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NpQ-ZKBNCa8"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/NpQ-ZKBNCa8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int, int> mp;
        int ans = 1;
        for(int x: arr) {
            mp[x] = 1 + max(mp[x - diff], mp.count(x)? mp[x] -1 :0);
            ans = max(ans, mp[x]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1218.md" >}}
---
{{< youtube NpQ-ZKBNCa8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1219: Path with Maximum Gold](https://grid47.xyz/leetcode/solution-1219-path-with-maximum-gold/) |
| --- |