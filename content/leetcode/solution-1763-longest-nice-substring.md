
+++
authors = ["grid47"]
title = "Leetcode 1763: Longest Nice Substring"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1763: Longest Nice Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Divide and Conquer","Bit Manipulation","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6WvZrynlCdk"
youtube_upload_date="2021-02-20"
youtube_thumbnail="https://i.ytimg.com/vi/6WvZrynlCdk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-nice-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string longestNiceSubstring(string s, int start = 0, int end = -1) {
        if (end == -1)
            end = s.size();
        int cnt[26][2] = {}, j = start - 1;
        for (auto i = start; i < end; ++i)
            cnt[tolower(s[i]) - 'a'][(bool)islower(s[i])] = 1;
        string res;
        for (auto i = start; i <= end; ++i) {
            int ch = i == end ? -1 : tolower(s[i]) - 'a';
            if (ch == -1 || cnt[ch][0] + cnt[ch][1] == 1) {
                if (j == -1 && ch == -1)
                    return s;
                auto res1 = longestNiceSubstring(s.substr(j + 1, i - j - 1));
                if (res1.size() > res.size())
                    res = res1;
                j = i;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1763.md" >}}
---
{{< youtube 6WvZrynlCdk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1764: Form Array by Concatenating Subarrays of Another Array](https://grid47.xyz/leetcode/solution-1764-form-array-by-concatenating-subarrays-of-another-array/) |
| --- |