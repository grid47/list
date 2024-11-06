
+++
authors = ["Crafted by Me"]
title = "Leetcode 757: Set Intersection Size At Least Two"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 757: Set Intersection Size At Least Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/set-intersection-size-at-least-two/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        int ans = 0, fst = -1, scd = -1;
        
        for(auto it: nums) {
            int a = it[0], b = it[1];
            
            bool is_fst_in = a <= fst;
            bool is_scd_in = a <= scd;
            
            if(is_fst_in && is_scd_in) continue;
            
            ans += is_fst_in ? 1: 2;
            
            scd = is_fst_in? fst: b-1;
            fst = b;
            
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/757.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #758: Bold Words in String](https://grid47.xyz/posts/leetcode_758) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

