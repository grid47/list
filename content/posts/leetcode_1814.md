
+++
authors = ["Yasir"]
title = "Leetcode 1814: Count Nice Pairs in an Array"
date = "2019-11-10"
description = "Solution to Leetcode 1814"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-nice-pairs-in-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int, long> mp;
        for(auto &n: nums) mp[n - rev(n)]++;
        
        int mod = 1000000007;
        long count = 0;
        
        for(auto &it: mp) 
        count = (count + (it.second * (it.second - 1))/ 2) % mod;
        
        return count;
    }

    int rev(int x) {
        int revNum = 0;
        while(x) revNum = revNum * 10 + (x%10), x /= 10;
        return revNum;
    }
};
{{< /highlight >}}

