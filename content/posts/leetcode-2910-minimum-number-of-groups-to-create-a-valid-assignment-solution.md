
+++
authors = ["grid47"]
title = "Leetcode 2910: Minimum Number of Groups to Create a Valid Assignment"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2913: Subarrays Distinct Element Sum of Squares I](https://grid47.xyz/posts/leetcode-2913-subarrays-distinct-element-sum-of-squares-i-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}