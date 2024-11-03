
+++
authors = ["Crafted by Me"]
title = "Leetcode 2750: Ways to Split Array Into Good Subarrays"
date = "2017-04-23"
description = "In-depth solution and explanation for Leetcode 2750: Ways to Split Array Into Good Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {

        int mod = (int) 1e9 + 7;
        long ans = 1, cnt = 0;
        int i = 0, n = nums.size();
        while(i < n && nums[i] == 0) cnt++, i++;
        if(cnt == n) return 0;
        cnt = 0;

        for(; i < n; i++) {
            if(nums[i]) {
                ans = (ans * (cnt + 1)) % mod;
                cnt = 0;
            } else cnt++;
        }
        return ans;
    }
};
{{< /highlight >}}


---


"| 2751: Robot Collisions |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

