
+++
authors = ["Crafted by Me"]
title = "Leetcode 2453: Destroy Sequential Targets"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2453: Destroy Sequential Targets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/destroy-sequential-targets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for(int n: nums) {
            int r = n % space;
            mp[r]++;
            if(mx < mp[r]) mx = mp[r];
        }
        for(int n : nums)
        if(mx == mp[n %space]) ans = min(ans, n);
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube zhvKbUSFzQ8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2454: Next Greater Element IV](https://grid47.xyz/posts/leetcode_2454) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

