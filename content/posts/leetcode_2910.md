
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2910: Minimum Number of Groups to Create a Valid Assignment"
date = "2016-11-12"
description = "Solution to Leetcode 2910"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-groups-to-create-a-valid-assignment/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

