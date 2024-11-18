
+++
authors = ["grid47"]
title = "Leetcode 2311: Longest Binary Subsequence Less Than or Equal to K"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2311: Longest Binary Subsequence Less Than or Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy","Memoization"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xgpPuMjET9c"
youtube_upload_date="2022-06-19"
youtube_thumbnail="https://i.ytimg.com/vi/xgpPuMjET9c/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0, cnt = 0, pow = 1;
        for(int i = s.size() - 1; i >= 0 && val + pow <= k; i--) {
            if(s[i] == '1') {
                ++cnt;
                val += pow;
            }
            pow <<= 1;
        }
        return count(s.begin(), s.end(), '0') + cnt;  
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2311.md" >}}
---
{{< youtube xgpPuMjET9c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2315: Count Asterisks](https://grid47.xyz/leetcode/solution-2315-count-asterisks/) |
| --- |
