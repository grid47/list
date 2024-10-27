
+++
authors = ["Yasir"]
title = "Leetcode 2364: Count Number of Bad Pairs"
date = "2018-05-09"
description = "Solution to Leetcode 2364"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-bad-pairs/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long countBadPairs(vector<int>& nums, long cnt = 0) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            cnt += i - mp[i - nums[i]]++;
        return cnt;
    }
};
{{< /highlight >}}

