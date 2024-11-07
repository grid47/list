
+++
authors = ["Crafted by Me"]
title = "Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        /* change one element to any other value in one move */
        /* get min diff between max and min value after performing atmost 3 moves */
        if(n < 5) return 0;
        sort(nums.begin(), nums.end());
        
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1509.md" >}}
---
{{< youtube SG7VnKzhfjo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1510: Stone Game IV](https://grid47.xyz/posts/leetcode_1510) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
