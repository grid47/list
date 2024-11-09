
+++
authors = ["grid47"]
title = "Leetcode 2748: Number of Beautiful Pairs"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2748: Number of Beautiful Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-beautiful-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int countBeautifulPairs(vector<int>& nums) {
    int cnt[10] = {}, res = 0;
    for(int i = 0; i < nums.size(); ++i) {
        for (int n = 1; n < 10; ++n)
            if (gcd(n, nums[i] % 10) == 1)
                res += cnt[n];
        while (nums[i] >= 10)
            nums[i] /= 10;
        ++cnt[nums[i]];
    }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2748.md" >}}
---
{{< youtube mjceDBNh7vg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2750: Ways to Split Array Into Good Subarrays](https://grid47.xyz/posts/leetcode-2750-ways-to-split-array-into-good-subarrays-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
