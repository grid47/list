
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2958: Length of Longest Subarray With at Most K Frequency"
date = "2016-09-24"
description = "Solution to Leetcode 2958"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        map<int, int> mp;
        int j = 0, res = 1, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            while(mp[nums[i]] > k) {
                mp[nums[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
