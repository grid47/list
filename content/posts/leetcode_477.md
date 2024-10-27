
+++
authors = ["Yasir"]
title = "Leetcode 477: Total Hamming Distance"
date = "2023-07-09"
description = "Solution to Leetcode 477"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/total-hamming-distance/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size();
        for(int i = 0; i < 32; i++) {
            int bitCnt = 0;
            for(int j = 0; j < nums.size(); j++)
                bitCnt += (nums[j] >> i) & 1;
            
            total += bitCnt * (n - bitCnt);
        }
        return total;
    }
};
{{< /highlight >}}

