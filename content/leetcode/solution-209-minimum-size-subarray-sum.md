
+++
authors = ["grid47"]
title = "Leetcode 209: Minimum Size Subarray Sum"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 209: Minimum Size Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/209.webp"
youtube = "RG17VCQOFpg"
youtube_upload_date="2024-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/RG17VCQOFpg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-size-subarray-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/209.webp" 
    alt="A glowing, shrinking subarray highlighting the smallest sum as it contracts into the minimal size."
    caption="Solution to LeetCode 209: Minimum Size Subarray Sum Problem"
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, idx = 0, g = INT_MAX, bdx = 0;
        while(idx < nums.size()) {
            sum += nums[idx];

            while(sum >= target) {
                g = min(g, idx - bdx + 1);
                sum -= nums[bdx];
                bdx++;
            }
            idx++;
        }
        return g == INT_MAX? 0: g;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/209.md" >}}
---
{{< youtube RG17VCQOFpg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #210: Course Schedule II](https://grid47.xyz/leetcode/solution-210-course-schedule-ii/) |
| --- |