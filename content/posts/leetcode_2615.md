
+++
authors = ["Crafted by Me"]
title = "Leetcode 2615: Sum of Distances"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2615: Sum of Distances in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-distances/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        /*
        
        [1,3,1,1,2]
         0,1,2,3,4
        
         0
           0  
         2   2
         5   3 4
                 0
        */
        
        unordered_map<int, double> mp, cnt;
        int n = nums.size();
        vector<long long> arr(n, 0);
        for(int i = 0; i < n; i++) {
            arr[i] = cnt[nums[i]] * i - mp[nums[i]];
            mp[nums[i]] += i;
            cnt[nums[i]] += 1;
        }
        mp.clear(), cnt.clear();        
        for(int i = n - 1; i >= 0; i--) {
            arr[i] += mp[nums[i]] - cnt[nums[i]] * i;
            mp[nums[i]] += i;
            cnt[nums[i]] += 1;
        }
        return arr;
    }
};
{{< /highlight >}}


---
{{< youtube b620guqinSc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2616: Minimize the Maximum Difference of Pairs](https://grid47.xyz/posts/leetcode_2616) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
