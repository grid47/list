
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2568: Minimum Impossible OR"
date = "2017-10-19"
description = "Solution to Leetcode 2568"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-impossible-or/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int> cnt;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            cnt.insert(nums[i]);
        }
        int ret = 1;
        while(cnt.count(ret)) {
            ret *= 2;
        }
        // to create all the numbers till a positive integer
        // presents of all the powers of 2s below it are mandatory.
        return ret;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
