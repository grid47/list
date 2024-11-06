
+++
authors = ["Crafted by Me"]
title = "Leetcode 2587: Rearrange Array to Maximize Prefix Score"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2587: Rearrange Array to Maximize Prefix Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        
        if(n == 1) return nums[0] > 0;
        int cnt = 0;
        
        long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum > 0) cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}


---
{{< youtube N3qkc7zT_a0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2588: Count the Number of Beautiful Subarrays](https://grid47.xyz/posts/leetcode_2588) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
