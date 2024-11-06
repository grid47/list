
+++
authors = ["Crafted by Me"]
title = "Leetcode 2501: Longest Square Streak in an Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2501: Longest Square Streak in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-square-streak-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i= 0; i < n; i++) {
            long long tmp = (long long) nums[i] * nums[i];
            if(tmp > INT_MAX) break;
            auto it = lower_bound(nums.begin(), nums.end(), tmp);
            if(it == nums.end()) break;
            int pos = it - nums.begin();
            while(pos < n && nums[i] * nums[i] == nums[pos]) {
                    dp[pos] = max(dp[pos], 1 + dp[i]);                
                    mx = max(mx, dp[pos]);  
                    pos++;
            }
        }
        return mx == 1? -1: mx;
    }
};
{{< /highlight >}}


---
{{< youtube prcJMNtokGI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2502: Design Memory Allocator](https://grid47.xyz/posts/leetcode_2502) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
