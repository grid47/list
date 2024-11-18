
+++
authors = ["grid47"]
title = "Leetcode 268: Missing Number"
date = "2024-10-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 268: Missing Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Binary Search","Bit Manipulation","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "WnPLSRLSANE"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/268.webp"
+++



[`Problem Link`](https://leetcode.com/problems/missing-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/268.webp" 
    alt="A series of numbers, with one missing number softly highlighted as the gap is revealed."
    caption="Solution to LeetCode 268: Missing Number Problem"
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
    int missingNumber(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
            sum ^= nums[i];
        for(int i = 0; i <= nums.size(); i++)
            sum ^= i;
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/268.md" >}}
---
{{< youtube WnPLSRLSANE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #278: First Bad Version](https://grid47.xyz/leetcode/solution-278-first-bad-version/) |
| --- |
