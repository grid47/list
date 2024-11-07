
+++
authors = ["Crafted by Me"]
title = "Leetcode 982: Triples with Bitwise AND Equal To Zero"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 982: Triples with Bitwise AND Equal To Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> mp(1<<16, 0);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            mp[nums[i] & nums[j]]++;
        }
        for(int i = 0; i < n; i++)
        for(int j = 0; j < (1 << 16); j++)
            if((j & nums[i]) == 0) res += mp[j];
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/982.md" >}}
---
{{< youtube 7ibf14FeknE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #983: Minimum Cost For Tickets](https://grid47.xyz/posts/leetcode_983) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
