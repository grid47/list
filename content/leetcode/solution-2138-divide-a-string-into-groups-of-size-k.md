
+++
authors = ["grid47"]
title = "Leetcode 2138: Divide a String Into Groups of Size k"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2138: Divide a String Into Groups of Size k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "J_aEpIkTv4k"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res((s.size() + k - 1) / k, string(k, fill));
        for (int i = 0; i < s.size(); ++i)
            res[i / k][i % k] = s[i];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2138.md" >}}
---
{{< youtube J_aEpIkTv4k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2139: Minimum Moves to Reach Target Score](https://grid47.xyz/leetcode/solution-2139-minimum-moves-to-reach-target-score/) |
| --- |
