
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2750: Ways to Split Array Into Good Subarrays"
date = "2017-04-21"
description = "Solution to Leetcode 2750"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {

        int mod = (int) 1e9 + 7;
        long ans = 1, cnt = 0;
        int i = 0, n = nums.size();
        while(i < n && nums[i] == 0) cnt++, i++;
        if(cnt == n) return 0;
        cnt = 0;

        for(; i < n; i++) {
            if(nums[i]) {
                ans = (ans * (cnt + 1)) % mod;
                cnt = 0;
            } else cnt++;
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

