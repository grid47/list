
+++
authors = ["grid47"]
title = "Leetcode 27: Remove Element"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 27: Remove Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/27.webp"
youtube = "Pcd1ii9P9ZI"
youtube_upload_date="2021-09-13"
youtube_thumbnail="https://i.ytimg.com/vi/Pcd1ii9P9ZI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/remove-element/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/27.webp" 
    alt="A soft, radiant element being gently pulled away from a sequence, leaving a streamlined flow."
    caption="Solution to LeetCode 27: Remove Element Problem"
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
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        
        for(int node: nums)
            if(node != val)
            {
                nums[i] = node;
                i++;
            }
        
        return i;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/27.md" >}}
---
{{< youtube Pcd1ii9P9ZI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #29: Divide Two Integers](https://grid47.xyz/leetcode/solution-29-divide-two-integers/) |
| --- |
