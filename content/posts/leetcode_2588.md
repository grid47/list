
+++
authors = ["Crafted by Me"]
title = "Leetcode 2588: Count the Number of Beautiful Subarrays"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2588: Count the Number of Beautiful Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n= nums.size();
        long long cnt = 0;
        map<int, int> mp;
        mp[0] = 1;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp ^= nums[i];
            if(mp.count(tmp)) cnt+= mp[tmp];
            mp[tmp]++;
        }
        return cnt;
    }
};
{{< /highlight >}}


---
{{< youtube JokGqRfyMPU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2589: Minimum Time to Complete All Tasks](https://grid47.xyz/posts/leetcode_2589) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
