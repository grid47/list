
+++
authors = ["Yasir"]
title = "Leetcode 1752: Check if Array Is Sorted and Rotated"
date = "2020-01-11"
description = "Solution to Leetcode 1752"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;
    }
};
{{< /highlight >}}

