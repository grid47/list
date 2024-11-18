
+++
authors = ["grid47"]
title = "Leetcode 1051: Height Checker"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1051: Height Checker in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Counting Sort"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mQAoeYaE3Xk"
youtube_upload_date="2024-06-10"
youtube_thumbnail="https://i.ytimg.com/vi/mQAoeYaE3Xk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/height-checker/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int heightChecker(vector<int>& h) {

        auto m = max_element(h.begin(), h.end());

        vector<int> exp(*m + 1);

        for (int height : h) exp[height]++;

        int res = 0;

        for (int j = 1, i = 0; j < exp.size(); j++)
            while (exp[j]--) res += (h[i++] != j);

        return res;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1051.md" >}}
---
{{< youtube mQAoeYaE3Xk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1052: Grumpy Bookstore Owner](https://grid47.xyz/leetcode/solution-1052-grumpy-bookstore-owner/) |
| --- |
