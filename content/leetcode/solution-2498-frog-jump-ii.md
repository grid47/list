
+++
authors = ["grid47"]
title = "Leetcode 2498: Frog Jump II"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2498: Frog Jump II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7zFq991SKgQ"
youtube_upload_date="2022-12-10"
youtube_thumbnail="https://i.ytimg.com/vi/7zFq991SKgQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/frog-jump-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxJump(vector<int>& A) {
        int res = A[1] - A[0];
        int n = A.size();
        for(int i = 2; i < n; i++)
            res = max(res, A[i] - A[i - 2]);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2498.md" >}}
---
{{< youtube 7zFq991SKgQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2500: Delete Greatest Value in Each Row](https://grid47.xyz/leetcode/solution-2500-delete-greatest-value-in-each-row/) |
| --- |