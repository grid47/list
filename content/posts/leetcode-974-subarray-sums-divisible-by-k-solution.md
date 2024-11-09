
+++
authors = ["grid47"]
title = "Leetcode 974: Subarray Sums Divisible by K"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 974: Subarray Sums Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), sum = 0;        
        vector<int> frq(k, 0);
        frq[0] = 1;
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            int rm = sum % k;
            if(rm < 0) rm += k;            
            res += frq[rm];
            frq[rm]++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/974.md" >}}
---
{{< youtube bcXy-T4Sc3E >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #977: Squares of a Sorted Array](https://grid47.xyz/posts/leetcode-977-squares-of-a-sorted-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
