
+++
authors = ["grid47"]
title = "Leetcode 540: Single Element in a Sorted Array"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 540: Single Element in a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/540.webp"
youtube = "T4nRgIxka18"
youtube_upload_date="2020-05-13"
youtube_thumbnail="https://i.ytimg.com/vi/T4nRgIxka18/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/540.webp" 
    alt="An array where the single unique element glows softly as it is found among duplicates."
    caption="Solution to LeetCode 540: Single Element in a Sorted Array Problem"
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
    int singleNonDuplicate(vector<int>& nums) {
        int res =0;
        for(int num : nums)
        res ^= num;

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/540.md" >}}
---
{{< youtube T4nRgIxka18 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #542: 01 Matrix](https://grid47.xyz/leetcode/solution-542-01-matrix/) |
| --- |
