
+++
authors = ["grid47"]
title = "Leetcode 2511: Maximum Enemy Forts That Can Be Captured"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2511: Maximum Enemy Forts That Can Be Captured in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "y7BwYY4UFak"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int captureForts(vector<int>& forts) {
    int res = 0;
    for (int i = 0, j = 0; i < forts.size(); ++i)
        if (forts[i] != 0) {
            if (forts[j] == -forts[i])
                res = max(res, i - j - 1);
            j = i;
        }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2511.md" >}}
---
{{< youtube y7BwYY4UFak >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2512: Reward Top K Students](https://grid47.xyz/leetcode/solution-2512-reward-top-k-students/) |
| --- |
