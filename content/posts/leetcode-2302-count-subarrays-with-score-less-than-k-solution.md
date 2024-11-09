
+++
authors = ["grid47"]
title = "Leetcode 2302: Count Subarrays With Score Less Than K"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2302: Count Subarrays With Score Less Than K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0, j = 0, res = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            while(sum * (i - j + 1) >= k) sum -= nums[j++];
            
            res += (i - j + 1);
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2302.md" >}}
---
{{< youtube IRUCdJCZxcE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2304: Minimum Path Cost in a Grid](https://grid47.xyz/posts/leetcode-2302-count-subarrays-with-score-less-than-k-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
