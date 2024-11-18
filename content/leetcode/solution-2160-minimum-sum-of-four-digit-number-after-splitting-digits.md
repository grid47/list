
+++
authors = ["grid47"]
title = "Leetcode 2160: Minimum Sum of Four Digit Number After Splitting Digits"
date = "2024-04-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2160: Minimum Sum of Four Digit Number After Splitting Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wH9FIi-39-w"
youtube_upload_date="2022-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wH9FIi-39-w/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution{
public:
    int minimumSum(int num){
        string s = to_string(num);
        sort(s.begin(), s.end());
        int res = (s[0] - '0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2160.md" >}}
---
{{< youtube wH9FIi-39-w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2161: Partition Array According to Given Pivot](https://grid47.xyz/leetcode/solution-2161-partition-array-according-to-given-pivot/) |
| --- |
