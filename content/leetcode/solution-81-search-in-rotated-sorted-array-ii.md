
+++
authors = ["grid47"]
title = "Leetcode 81: Search in Rotated Sorted Array II"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 81: Search in Rotated Sorted Array II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/81.webp"
youtube = "oUnF7o88_Xc"
youtube_upload_date="2023-08-10"
youtube_thumbnail="https://i.ytimg.com/vi/oUnF7o88_Xc/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/81.webp" 
    alt="A rotating array with elements softly shifting in a clockwise direction."
    caption="Solution to LeetCode 81: Search in Rotated Sorted Array II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---
{{< youtube oUnF7o88_Xc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #86: Partition List](https://grid47.xyz/leetcode/solution-86-partition-list/) |
| --- |