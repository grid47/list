
+++
authors = ["Crafted by Me"]
title = "Leetcode 2256: Minimum Average Difference"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2256: Minimum Average Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-average-difference/description/)

---

**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        typedef long long ll;
        
        ll sum = 0;
        for(int a : nums) sum += a;

        ll n = nums.size(), res = INT_MAX, ret = 0, la = 0, ra = 0;
        ll l = 0, r = sum;
        for(int i = 0; i < n; i++) {
            int prv = res;
            l += nums[i];
            r -= nums[i];      
            la = l / (i + 1);
            ra = (i+1==n)?0:r / (n-(i+1));
            res = min(res, abs(la - ra));
            if(prv != res) ret = i;
        }
        return ret;            
    }
};
{{< /highlight >}}


---
{{< youtube rh8Mnj9Bd64 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2257: Count Unguarded Cells in the Grid](https://grid47.xyz/posts/leetcode_2257) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

