
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2170: Minimum Operations to Make the Array Alternating"
date = "2018-11-20"
description = "Solution to Leetcode 2170"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

