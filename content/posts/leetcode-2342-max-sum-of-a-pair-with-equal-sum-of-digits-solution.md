
+++
authors = ["grid47"]
title = "Leetcode 2342: Max Sum of a Pair With Equal Sum of Digits"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2342: Max Sum of a Pair With Equal Sum of Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        map<int, int> mp;
        
        int ans = -1;
        
        for(int x: nums) {
            int sum = 0;
            int tmp = x;
            while(tmp > 0) {
                sum += (tmp % 10);
                tmp /= 10;
            }
            if(mp.count(sum)) {
                ans = max(ans, x + mp[sum]);
                mp[sum] = max(x, mp[sum]);
            } else {
                mp[sum] = x;
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2342.md" >}}
---
{{< youtube uOPtnfVSFuQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2343: Query Kth Smallest Trimmed Number](https://grid47.xyz/posts/leetcode-2343-query-kth-smallest-trimmed-number-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}