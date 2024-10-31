
+++
authors = ["Crafted by Me"]
title = "Leetcode 1004: Max Consecutive Ones III"
date = "2022-02-01"
description = "Solution to Leetcode 1004"
tags = [
    
]
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



---

{{< youtube HsGKI02yw6M >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

