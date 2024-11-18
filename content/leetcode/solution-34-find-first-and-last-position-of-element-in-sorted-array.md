
+++
authors = ["grid47"]
title = "Leetcode 34: Find First and Last Position of Element in Sorted Array"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 34: Find First and Last Position of Element in Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/34.webp"
youtube = "4sQL7R5ySUU"
youtube_upload_date="2021-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4sQL7R5ySUU/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/34.webp" 
    alt="A soft glowing bar where the positions of elements light up in sequence."
    caption="Solution to LeetCode 34: Find First and Last Position of Element in Sorted Array Problem"
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
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);

        if(it1 == nums.end() || *it1 != target) return {-1, -1};

        return {(int) (it1 - nums.begin()), (int) (it2 - nums.begin() - 1)};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/34.md" >}}
---
{{< youtube 4sQL7R5ySUU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #35: Search Insert Position](https://grid47.xyz/leetcode/solution-35-search-insert-position/) |
| --- |
