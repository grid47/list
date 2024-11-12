
+++
authors = ["grid47"]
title = "Leetcode 2343: Query Kth Smallest Trimmed Number"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2343: Query Kth Smallest Trimmed Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Divide and Conquer","Sorting","Heap (Priority Queue)","Radix Sort","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> res;
        for(auto &v : q) {
            
            vector<pair<string, int>> fk;
            for(int i = 0; i < nums.size(); i++) {
                fk.push_back({nums[i].substr(nums[i].size() - v[1]), i});
            }
            sort(fk.begin(), fk.end());
            res.push_back(fk[v[0] - 1].second);
            
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2343.md" >}}
---
{{< youtube E93-thIrUgA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2347: Best Poker Hand](https://grid47.xyz/posts/leetcode-2347-best-poker-hand-solution/) |
| --- |
