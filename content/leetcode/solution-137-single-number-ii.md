
+++
authors = ["grid47"]
title = "Leetcode 137: Single Number II"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 137: Single Number II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "cOFAmaMBVps"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/137.webp"
+++



[`Problem Link`](https://leetcode.com/problems/single-number-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/137.webp" 
    alt="Two radiant numbers standing out in a sequence, one representing the unique element and the other repeating."
    caption="Solution to LeetCode 137: Single Number II Problem"
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
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        int ones = 0, twos = 0;
        for(int i = 0; i < n; i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;            
        }
        return ones;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/137.md" >}}
---
{{< youtube cOFAmaMBVps >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #138: Copy List with Random Pointer](https://grid47.xyz/leetcode/solution-138-copy-list-with-random-pointer/) |
| --- |
