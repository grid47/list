
+++
authors = ["Crafted by Me"]
title = "Leetcode 2293: Min Max Game"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2293: Min Max Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/min-max-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1) return nums[0];  // Base case
        vector<int> newNum(n/2); 
        for(int i=0; i<n/2; i++) { 
            if(i%2==0) newNum[i] = min(nums[2 * i], nums[2 * i + 1]); 
            else newNum[i] = max(nums[2 * i], nums[2 * i + 1]); 
        } 
        int res = minMaxGame(newNum); // Recursive call
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube ZDZ4KQsbnbc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2294: Partition Array Such That Maximum Difference Is K](https://grid47.xyz/posts/leetcode_2294) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

