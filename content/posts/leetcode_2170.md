
+++
authors = ["Crafted by Me"]
title = "Leetcode 2170: Minimum Operations to Make the Array Alternating"
date = "2018-11-24"
description = "In-depth solution and explanation for Leetcode 2170: Minimum Operations to Make the Array Alternating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    array<int, 3> top2Freq(vector<int>& nums, int start) {
        int first = 0, second = 0, cnt[100001] = {};
        for(int i = start; i < nums.size(); i += 2) {
            if(++cnt[nums[i]] >= cnt[first]) {
                if(nums[i] != first)
                    second = first;
                first = nums[i];
            } else if(cnt[nums[i]] > cnt[second]) second = nums[i];
        }
        return {first, cnt[first], cnt[second] };
    }

    int minimumOperations(vector<int>& nums) {
        auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
        return nums.size() - (ev[0] != od[0]? ev[1] + od[1] : max(ev[1]+ od[2], ev[2] + od[1]));
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2171: Removing Minimum Number of Magic Beans](grid47.xyz/leetcode_2171) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

