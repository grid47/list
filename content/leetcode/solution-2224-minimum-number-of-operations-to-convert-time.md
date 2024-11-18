
+++
authors = ["grid47"]
title = "Leetcode 2224: Minimum Number of Operations to Convert Time"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2224: Minimum Number of Operations to Convert Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "N_iV4VXnq6g"
youtube_upload_date="2022-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/N_iV4VXnq6g/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    int getTime(string &s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
public:
    int convertTime(string current, string correct) {
        int diff = getTime(correct) - getTime(current), ops[4] = {60,15,5,1}, ans = 0;
        for (int op : ops) {
            ans += diff / op;
            diff %= op;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2224.md" >}}
---
{{< youtube N_iV4VXnq6g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2225: Find Players With Zero or One Losses](https://grid47.xyz/leetcode/solution-2225-find-players-with-zero-or-one-losses/) |
| --- |
