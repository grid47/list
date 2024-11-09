
+++
authors = ["grid47"]
title = "Leetcode 2366: Minimum Replacements to Sort the Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2366: Minimum Replacements to Sort the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = 0, prv = nums[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            int cnt = nums[i] / prv;
            if(nums[i] % prv != 0) {
                cnt++;
                prv = nums[i] / cnt;
            }
            ans += cnt - 1;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2366.md" >}}
---
{{< youtube 0CU_aJ1SW6k >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2367: Number of Arithmetic Triplets](https://grid47.xyz/posts/leetcode-2367-number-of-arithmetic-triplets-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
