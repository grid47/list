
+++
authors = ["Crafted by Me"]
title = "Leetcode 2366: Minimum Replacements to Sort the Array"
date = "2018-05-11"
description = "Solution to Leetcode 2366"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = 0, prv = nums[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            int cnt = nums[i] / prv;
            if(nums[i] % prv != 0) {
                cnt++;
                prv = nums[i] / cnt;
            }
            ans += cnt - 1;
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

