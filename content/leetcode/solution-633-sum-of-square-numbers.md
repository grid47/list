
+++
authors = ["grid47"]
title = "Leetcode 633: Sum of Square Numbers"
date = "2024-09-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 633: Sum of Square Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/633.webp"
youtube = "B0UrG_X2faA"
youtube_upload_date="2024-06-17"
youtube_thumbnail="https://i.ytimg.com/vi/B0UrG_X2faA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-square-numbers/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/633.webp" 
    alt="A series of squares where the sum of square numbers is calculated and softly glowing as it’s computed."
    caption="Solution to LeetCode 633: Sum of Square Numbers Problem"
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
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while(left <= right) {
            long res = left * left + right * right;
            if(res < c)
            left++;
            else if(res > c) 
            right--;
            else return true;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/633.md" >}}
---
{{< youtube B0UrG_X2faA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #636: Exclusive Time of Functions](https://grid47.xyz/leetcode/solution-636-exclusive-time-of-functions/) |
| --- |