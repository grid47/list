
+++
authors = ["grid47"]
title = "Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "kv0O7p0pRvI"
youtube_upload_date="2022-05-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kv0O7p0pRvI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
bool digitCount(string num) {
    int cnt[10] = {};
    for (auto n : num)
        ++cnt[n - '0'];
    for (int i = 0; i < num.size(); ++i)
        if (cnt[i] != num[i] - '0')
            return false;
    return true;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2283.md" >}}
---
{{< youtube kv0O7p0pRvI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2284: Sender With Largest Word Count](https://grid47.xyz/leetcode/solution-2284-sender-with-largest-word-count/) |
| --- |
