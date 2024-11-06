
+++
authors = ["Crafted by Me"]
title = "Leetcode 2104: Sum of Subarray Ranges"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2104: Sum of Subarray Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-subarray-ranges/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long res = 0, n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            
            int mini = nums[i], maxi = nums[i];
            
            for(int j = i + 1; j < n; j++) {
                
                if(nums[j] < mini) mini = nums[j];
                if(nums[j] > maxi) maxi = nums[j];
                res += maxi - mini;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube sMFAjHe3kkw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2105: Watering Plants II](https://grid47.xyz/posts/leetcode_2105) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
