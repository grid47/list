
+++
authors = ["grid47"]
title = "Leetcode 1760: Minimum Limit of Balls in a Bag"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1760: Minimum Limit of Balls in a Bag in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSize(vector<int>& nums, int mxOps) {
        
        int l = 1, r = *max_element(nums.begin(), nums.end());
        // int total_bags = n + 2 * mxOps - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int a: nums)
                cnt += (a - 1) / mid;
            if(cnt <= mxOps)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1760.md" >}}
---
{{< youtube znZ4wT1L8Y0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1761: Minimum Degree of a Connected Trio in a Graph](https://grid47.xyz/posts/leetcode-1761-minimum-degree-of-a-connected-trio-in-a-graph-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}