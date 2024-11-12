
+++
authors = ["grid47"]
title = "Leetcode 2588: Count the Number of Beautiful Subarrays"
date = "2024-02-22"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2588.md" >}}
---
{{< youtube JokGqRfyMPU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2591: Distribute Money to Maximum Children](https://grid47.xyz/posts/leetcode-2591-distribute-money-to-maximum-children-solution/) |
| --- |
