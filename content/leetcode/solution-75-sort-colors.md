
+++
authors = ["grid47"]
title = "Leetcode 75: Sort Colors"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 75: Sort Colors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/75.webp"
youtube = "4xbWSRZHqac"
youtube_upload_date="2021-06-24"
youtube_thumbnail="https://i.ytimg.com/vi/4xbWSRZHqac/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/sort-colors/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/75.webp" 
    alt="A radiant sequence of colors gently sorting themselves in a peaceful, fluid motion."
    caption="Solution to LeetCode 75: Sort Colors Problem"
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
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        
        for(int k = 0; k < n; k++) {
            
            while(nums[k] == 2 && k < j) {
                swap(nums[k], nums[j--]);                
            }
            while(nums[k] == 0 && k > i) {
                swap(nums[k], nums[i++]);  
            }
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/75.md" >}}
---
{{< youtube 4xbWSRZHqac >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #77: Combinations](https://grid47.xyz/leetcode/solution-77-combinations/) |
| --- |