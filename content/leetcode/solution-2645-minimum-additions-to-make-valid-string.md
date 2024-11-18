
+++
authors = ["grid47"]
title = "Leetcode 2645: Minimum Additions to Make Valid String"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2645: Minimum Additions to Make Valid String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7IAA0sdeACw"
youtube_upload_date="2023-04-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/7IAA0sdeACw/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int addMinimum(string word) {
        int exp = 0, res = 0;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            if(exp == (word[i] - 'a')) {
                exp = (exp + 1) % 3;
                continue;
            }
            while(exp != (word[i] - 'a')) {
                res++;
                exp = (exp + 1) % 3;
            }
            exp = (exp + 1) % 3;            
            // cout << i << " " << res << " " << exp << "\n";
        }
        if(word[n - 1] == 'a') res += 2;
        if(word[n - 1] == 'b') res += 1;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2645.md" >}}
---
{{< youtube 7IAA0sdeACw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2651: Calculate Delayed Arrival Time](https://grid47.xyz/leetcode/solution-2651-calculate-delayed-arrival-time/) |
| --- |
