
+++
authors = ["grid47"]
title = "Leetcode 2461: Maximum Sum of Distinct Subarrays With Length K"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2461: Maximum Sum of Distinct Subarrays With Length K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long sum = 0, ans = 0;
        int n = nums.size(), j = 0;
        
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            
            sum += nums[i];
            mp[nums[i]]++;
            
            while(i - j + 1 > k || mp[nums[i]] > 1) {
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            if((i - j + 1) == k) {
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2461.md" >}}
---
{{< youtube o8XmnEBQrLs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2462: Total Cost to Hire K Workers](https://grid47.xyz/posts/leetcode-2462-total-cost-to-hire-k-workers-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
