
+++
authors = ["grid47"]
title = "Leetcode 1004: Max Consecutive Ones III"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1004: Max Consecutive Ones III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt[2] = {};
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            while(cnt[0] > k && j <= i) {
                cnt[nums[j]]--;
                j++;
            }
            res = max(res, (i - j + 1));
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1004.md" >}}
---
{{< youtube HsGKI02yw6M >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1005: Maximize Sum Of Array After K Negations](https://grid47.xyz/posts/leetcode-1004-max-consecutive-ones-iii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
