
+++
authors = ["grid47"]
title = "Leetcode 2134: Minimum Swaps to Group All 1's Together II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2134: Minimum Swaps to Group All 1's Together II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0, x = 0, onesInWindows = 0, i = 0, n = nums.size();
        ones = count(nums.begin(), nums.end(), 1);
        vector<int> nums2(2 *n);
        for(int i = 0; i < 2 * n; i++)
        nums2[i] = nums[i%n];
        for(int i = 0; i < 2 *n ; i++) {
            if(i >= ones && nums2[i - ones] == 1) x--;
            if(nums2[i] == 1) x++;
            onesInWindows = max(x, onesInWindows);
        }
        return ones - onesInWindows;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2134.md" >}}
---
{{< youtube BueoreUIkcE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2135: Count Words Obtained After Adding a Letter](https://grid47.xyz/posts/leetcode_2135) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
