
+++
authors = ["Yasir"]
title = "Leetcode 1991: Find the Middle Index in Array"
date = "2019-05-17"
description = "Solution to Leetcode 1991"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-middle-index-in-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; i++)
            sum[i + 1] = nums[i] + sum[i];
        
        int net = sum[n];
        
        for(int i = 0; i < n; i++) {
            if(net - sum[i + 1] == sum[i]) return i;
        }
        return -1;
    }
};
{{< /highlight >}}

