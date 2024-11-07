
+++
authors = ["Crafted by Me"]
title = "Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        int sum = 0, lsize = INT_MAX, result = INT_MAX;
        mp[0] = -1;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            mp[sum] = i;
        }
        sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(mp.count(sum - target)) 
            lsize = min(lsize, i - mp[sum-target]);

            if(mp.count(sum + target) && lsize < INT_MAX)
            result = min(result, mp[sum + target] -i +lsize);


        }

        return result == INT_MAX ? -1: result;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1477.md" >}}
---
{{< youtube uV_JsPPLK9o >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1480: Running Sum of 1d Array](https://grid47.xyz/posts/leetcode_1480) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
