
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 81: Search in Rotated Sorted Array II"
date = "2024-08-10"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/81.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

