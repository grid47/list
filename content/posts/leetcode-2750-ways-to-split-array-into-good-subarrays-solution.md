
+++
authors = ["grid47"]
title = "Leetcode 2750: Ways to Split Array Into Good Subarrays"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2750: Ways to Split Array Into Good Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {

        int mod = (int) 1e9 + 7;
        long ans = 1, cnt = 0;
        int i = 0, n = nums.size();
        while(i < n && nums[i] == 0) cnt++, i++;
        if(cnt == n) return 0;
        cnt = 0;

        for(; i < n; i++) {
            if(nums[i]) {
                ans = (ans * (cnt + 1)) % mod;
                cnt = 0;
            } else cnt++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2750.md" >}}
---
{{< youtube T8f9ppAJHbY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2760: Longest Even Odd Subarray With Threshold](https://grid47.xyz/posts/leetcode-2760-longest-even-odd-subarray-with-threshold-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}