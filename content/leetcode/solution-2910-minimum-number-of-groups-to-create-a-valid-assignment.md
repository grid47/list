
+++
authors = ["grid47"]
title = "Leetcode 2910: Minimum Number of Groups to Create a Valid Assignment"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2910: Minimum Number of Groups to Create a Valid Assignment in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-groups-to-create-a-valid-assignment/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int split(unordered_map<int, int> &cnt, int g1) {
        int groups = 0, g = g1 - 1;
        for (const auto &[_, c] : cnt) {
            int group_cnt = c / g1, last_group = c % g1;
            if (last_group && last_group + group_cnt < g)
                return INT_MAX;
            groups += group_cnt + (last_group > 0);
        }
        return groups;
    }

    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto n : nums)
            ++cnt[n];
        int g = min_element(begin(cnt), end(cnt), [](const auto &p1, const auto &p2){
            return p1.second < p2.second;})->second;
        for (; split(cnt, g + 1) == INT_MAX; --g) ;
        return split(cnt, g + 1);
    }

};

{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2910.md" >}}
---
{{< youtube -upnA7dVDU0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2913: Subarrays Distinct Element Sum of Squares I](https://grid47.xyz/leetcode/solution-2913-subarrays-distinct-element-sum-of-squares-i/) |
| --- |
