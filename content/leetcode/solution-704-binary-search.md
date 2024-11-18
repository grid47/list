
+++
authors = ["grid47"]
title = "Leetcode 704: Binary Search"
date = "2024-08-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 704: Binary Search in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/704.webp"
youtube = "PissfOvEH7Q"
youtube_upload_date="2023-04-01"
youtube_thumbnail="https://i.ytimg.com/vi/PissfOvEH7Q/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/binary-search/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/704.webp" 
    alt="A sorted array where binary search is applied, each step softly glowing to highlight the search process."
    caption="Solution to LeetCode 704: Binary Search Problem"
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
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/704.md" >}}
---
{{< youtube PissfOvEH7Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #705: Design HashSet](https://grid47.xyz/leetcode/solution-705-design-hashset/) |
| --- |
