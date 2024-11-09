
+++
authors = ["grid47"]
title = "Leetcode 2762: Continuous Subarrays"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2762: Continuous Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Sliding Window","Heap (Priority Queue)","Ordered Set","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/continuous-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int i = 0, j = 0,n=nums.size();
        map<int,int> mp;
        while(j<n) {
            mp[nums[j]]++;
            while(mp.size()>3 || abs(mp.begin()->first - mp.rbegin()->first) > 2) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            long long temp = j-i+1;
            res = res + temp;
            j++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2762.md" >}}
---
{{< youtube TDB2fGaYzMg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2765: Longest Alternating Subarray](https://grid47.xyz/posts/leetcode-2765-longest-alternating-subarray-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
