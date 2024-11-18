
+++
authors = ["grid47"]
title = "Leetcode 11: Container With Most Water"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 11: Container With Most Water in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/11.webp"
youtube = "Y_4_or0Sc7I"
youtube_upload_date="2024-02-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Y_4_or0Sc7I/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/container-with-most-water/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/11.webp" 
    alt="A serene water container being filled with calming light, symbolizing capacity and volume."
    caption="Solution to LeetCode 11: Container With Most Water Problem"
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
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() -1;
        
        while(i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j])
                i++;
            else j--;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/11.md" >}}
---
{{< youtube Y_4_or0Sc7I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #12: Integer to Roman](https://grid47.xyz/leetcode/solution-12-integer-to-roman/) |
| --- |
