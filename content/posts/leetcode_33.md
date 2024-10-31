
+++
authors = ["Crafted by Me"]
title = "Leetcode 33: Search in Rotated Sorted Array"
date = "2024-09-29"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/33.md" >}}
---
{{< youtube U8XENwh8Oy8 >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

