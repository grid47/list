
+++
authors = ["Crafted by Me"]
title = "Leetcode 2411: Smallest Subarrays With Maximum Bitwise OR"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2411: Smallest Subarrays With Maximum Bitwise OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Bit Manipulation","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n, 1), last(30, 0);
        
        
        for(int i = n - 1; i >= 0; i--) {
            
            
            for(int j = 0; j < 30; j++) {
                
                if(nums[i] & (1 << j)) {
                    last[j] = i;
                }
                
                ans[i] = max(ans[i], last[j] - i + 1);
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube 0xR5bFyo2QA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2412: Minimum Money Required Before Transactions](https://grid47.xyz/posts/leetcode_2412) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
