
+++
authors = ["Yasir"]
title = "Leetcode 81: Search in Rotated Sorted Array II"
date = "2024-08-07"
description = "Solution to Leetcode 81"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
     int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }        
        
};
{{< /highlight >}}

