
+++
authors = ["grid47"]
title = "Leetcode 35: Search Insert Position"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 35: Search Insert Position in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "K-RYzDZkzCI"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/35.webp"
+++



[`Problem Link`](https://leetcode.com/problems/search-insert-position/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/35.webp" 
    alt="A glowing insertion point in a calm array, gently creating a new position."
    caption="Solution to LeetCode 35: Search Insert Position Problem"
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
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/35.md" >}}
---
{{< youtube K-RYzDZkzCI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #36: Valid Sudoku](https://grid47.xyz/leetcode/solution-36-valid-sudoku/) |
| --- |
