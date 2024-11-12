
+++
authors = ["grid47"]
title = "Leetcode 57: Insert Interval"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 57: Insert Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/insert-interval/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/57.webp" 
    alt="A glowing new interval gently being inserted into an existing flow of light."
    caption="Solution to LeetCode 57: Insert Interval Problem"
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
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& n) {
        vector<vector<int>> ans;
        int i = 0;
        while(i < it.size() && it[i][1] < n[0]) {
            ans.push_back(it[i]);
            i++;
        }
        
        while(i < it.size() && it[i][0] <= n[1]) {
            n = {
                min(it[i][0], n[0]),
                max(it[i][1], n[1])
            };
            i++;
        }
        ans.push_back(n);
        while(i < it.size()) {
            ans.push_back(it[i++]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/57.md" >}}
---
{{< youtube A8NUOmlwOlM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #59: Spiral Matrix II](https://grid47.xyz/posts/leetcode-59-spiral-matrix-ii-solution/) |
| --- |
