
+++
authors = ["grid47"]
title = "Leetcode 324: Wiggle Sort II"
date = "2024-10-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 324: Wiggle Sort II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Greedy","Sorting","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/324.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/wiggle-sort-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/324.webp" 
    alt="A sequence of numbers gently oscillating, with the elements arranged to form a wiggle pattern."
    caption="Solution to LeetCode 324: Wiggle Sort II Problem"
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
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        #define A(i) nums[(1 + 2 * i) % (n|1)]
        
        int i = 0, j = 0, k = n - 1;
        
        while(j <= k) {
            if(A(j) < mid)
                swap(A(j), A(k--));
            else if(A(j) > mid)
                swap(A(i++), A(j++));
            else j++;
        }
        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/324.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #328: Odd Even Linked List](https://grid47.xyz/leetcode/solution-328-odd-even-linked-list/) |
| --- |
