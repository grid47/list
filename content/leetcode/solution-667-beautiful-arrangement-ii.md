
+++
authors = ["grid47"]
title = "Leetcode 667: Beautiful Arrangement II"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 667: Beautiful Arrangement II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "A8-_z6gurGc"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/667.webp"
+++



[`Problem Link`](https://leetcode.com/problems/beautiful-arrangement-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/667.webp" 
    alt="A set of arrangements where the beautiful ones glow softly, based on the rules of arrangement."
    caption="Solution to LeetCode 667: Beautiful Arrangement II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for(int i = 1, j = n; i <= j; ) {
            if(k > 0) {
                res.push_back(k--%2? i++: j--);
            } else res.push_back(i++);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/667.md" >}}
---
{{< youtube A8-_z6gurGc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #669: Trim a Binary Search Tree](https://grid47.xyz/leetcode/solution-669-trim-a-binary-search-tree/) |
| --- |
