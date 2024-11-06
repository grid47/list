
+++
authors = ["Crafted by Me"]
title = "Leetcode 1481: Least Number of Unique Integers after K Removals"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1481: Least Number of Unique Integers after K Removals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto m : arr) mp[m]++;

        sort(begin(arr), end(arr), [&](int x, int y) {
            return mp[x] != mp[y] ? mp[x] < mp[y] : x < y;
        });

        unordered_set<int> st;
        for(int i = k; i < arr.size(); i++) st.insert(arr[i]);

        return st.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1481.md" >}}
---
{{< youtube Nsp_ta7SlEk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1482: Minimum Number of Days to Make m Bouquets](https://grid47.xyz/posts/leetcode_1482) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
