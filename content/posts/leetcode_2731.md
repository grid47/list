
+++
authors = ["grid47"]
title = "Leetcode 2731: Movement of Robots"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2731: Movement of Robots in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Brainteaser","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/movement-of-robots/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        for(int i = 0; i < nums.size(); i++) {
            if(s[i] == 'L') nums[i] -= d;
            else nums[i] += d;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0, dist = 0, mod = (int) 1e9 + 7;
        for(int i = 1; i < n; i++) {
            dist += ((long)nums[i] - nums[i - 1]) * (i);
            ans = (ans + dist) % mod;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2731.md" >}}
---
{{< youtube L86PHNze5RM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2732: Find a Good Subset of the Matrix](https://grid47.xyz/posts/leetcode_2732) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
