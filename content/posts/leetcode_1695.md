
+++
authors = ["Crafted by Me"]
title = "Leetcode 1695: Maximum Erasure Value"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1695: Maximum Erasure Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-erasure-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        map<int, int> mp;
        
        int mx = 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            sum += nums[i];
            
            while(mp[nums[i]] > 1) {
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            
            mx = max(mx, sum);
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1695.md" >}}
---
{{< youtube XIFl0gXnq9s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1696: Jump Game VI](https://grid47.xyz/posts/leetcode_1696) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
