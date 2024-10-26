
+++
authors = ["Yasir"]
title = "Leetcode 704: Binary Search"
date = "2022-11-23"
description = "Solution to Leetcode 704"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-search/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
{{< /highlight >}}

