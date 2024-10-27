
+++
authors = ["Yasir"]
title = "Leetcode 982: Triples with Bitwise AND Equal To Zero"
date = "2022-02-19"
description = "Solution to Leetcode 982"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> mp(1<<16, 0);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            mp[nums[i] & nums[j]]++;
        }
        for(int i = 0; i < n; i++)
        for(int j = 0; j < (1 << 16); j++)
            if((j & nums[i]) == 0) res += mp[j];
        
        return res;
    }
};
{{< /highlight >}}

