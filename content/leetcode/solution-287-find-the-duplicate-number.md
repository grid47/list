
+++
authors = ["grid47"]
title = "Leetcode 287: Find the Duplicate Number"
date = "2024-10-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 287: Find the Duplicate Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/287.webp"
youtube = "P5Knc5OmL2o"
youtube_upload_date="2023-09-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/P5Knc5OmL2o/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-duplicate-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/287.webp" 
    alt="A series of numbers, with the duplicate gently glowing and standing out from the rest."
    caption="Solution to LeetCode 287: Find the Duplicate Number Problem"
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
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/287.md" >}}
---
{{< youtube P5Knc5OmL2o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #300: Longest Increasing Subsequence](https://grid47.xyz/leetcode/solution-300-longest-increasing-subsequence/) |
| --- |