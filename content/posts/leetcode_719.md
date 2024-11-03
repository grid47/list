
+++
authors = ["Crafted by Me"]
title = "Leetcode 719: Find K-th Smallest Pair Distance"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 719: Find K-th Smallest Pair Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];
        
        for(int cnt = 0; l < r; cnt = 0) {
            int m = l + (r - l) / 2;
            
            for(int i = 0, j = 0; i < n; i++) {
                while(j < n && nums[j] <= nums[i] + m) j++;
                cnt += (j - i - 1);
            }
            
            if(cnt < k) {
                l = m + 1;
            } else r = m;
        }
        
        return l;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/719.md" >}}
---
{{< youtube bQ-QcFKwsZc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #720: Longest Word in Dictionary](https://grid47.xyz/posts/leetcode_720) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

