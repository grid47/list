
+++
authors = ["grid47"]
title = "Leetcode 1442: Count Triplets That Can Form Two Arrays of Equal XOR"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1442: Count Triplets That Can Form Two Arrays of Equal XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTriplets(vector<int>& nums) {

        int res = 0, n = nums.size();
        vector<int> arr(n+1,0);
        for(int i = 1; i < n + 1; i++)
            arr[i] = arr[i -1] ^ nums[i-1];
        for(int i = 0; i < n+1; i++) {
            for(int j = i + 1; j < n+1; j++)
                if(arr[i] == arr[j])
                res += j - i- 1;
            }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1442.md" >}}
---
{{< youtube e4Yx9KjqzQ8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1443: Minimum Time to Collect All Apples in a Tree](https://grid47.xyz/posts/leetcode_1443) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
