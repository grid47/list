
+++
authors = ["grid47"]
title = "Leetcode 16: 3Sum Closest"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 16: 3Sum Closest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/16.webp"
youtube = "PXWT4wzkA6M"
youtube_upload_date="2024-07-29"
youtube_thumbnail="https://i.ytimg.com/vi/PXWT4wzkA6M/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/3sum-closest/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/16.webp" 
    alt="Three glowing points forming a close triangle, with the central point shimmering in light."
    caption="Solution to LeetCode 16: 3Sum Closest Problem"
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int front;
        int sum = nums[0] + nums[1] + nums[2], sum1 = 0;

        for(int i = 0; i < nums.size(); i++) {

            front = i + 1;

            int back = nums.size() - 1;

            while( front < back ) {

                sum1 = nums[front] + nums[back] + nums[i];

                if (abs(sum1-target) <= abs(sum-target)) sum = sum1;

                     if(sum1 > target) back--;
                else if(sum1 < target) front++;
                else return sum1;

            }
        }

        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/16.md" >}}
---
{{< youtube PXWT4wzkA6M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #17: Letter Combinations of a Phone Number](https://grid47.xyz/leetcode/solution-17-letter-combinations-of-a-phone-number/) |
| --- |