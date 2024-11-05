
+++
authors = ["Crafted by Me"]
title = "Leetcode 3026: Maximum Good Subarray Sum"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 3026: Maximum Good Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-good-subarray-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = LLONG_MIN;

        int n = nums.size();
        map<int, int> mp;
        vector<long long> pre;
        pre.push_back(0);
        for(int i = 0; i < n; i++) {
            pre.push_back(pre.back() + nums[i]);
            if(mp.count(nums[i] - k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] - k]]);
            if(mp.count(nums[i] + k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] + k]]);
            auto it = mp.find(nums[i]);
            if(it == mp.end() || pre[i] - pre[it->second] <= 0) mp[nums[i]] = i;
        }
        return ans == LLONG_MIN? 0: ans;
    }
};
{{< /highlight >}}


---
{{< youtube v-IFLS8-Haw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3027: Find the Number of Ways to Place People II](https://grid47.xyz/posts/leetcode_3027) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

