
+++
authors = ["Yasir"]
title = "Leetcode 33: Search in Rotated Sorted Array"
date = "2024-09-26"
description = "Solution to Leetcode 33"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while(s <= e) {
            int mid = s + (e - s + 1) / 2;
            if(nums[mid] == target) return mid;
            if(nums[s] <= nums[mid]) {// window contain jerk
                if(nums[s] <= target && target < nums[mid])
                    e = mid - 1;
                else s = mid + 1;
            } else {// window is linear
                if(nums[mid] < target && target <= nums[e])
                    s = mid + 1;
                else e = mid - 1;
            }
        }
        return -1;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

