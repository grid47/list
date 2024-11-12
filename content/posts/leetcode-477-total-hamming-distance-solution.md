
+++
authors = ["grid47"]
title = "Leetcode 477: Total Hamming Distance"
date = "2024-09-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 477: Total Hamming Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/total-hamming-distance/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/477.webp" 
    alt="A sequence of binary strings where the total Hamming distance is calculated, with each distance step gently highlighted"
    caption="Solution to LeetCode 477: Total Hamming Distance Problem"
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
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size();
        for(int i = 0; i < 32; i++) {
            int bitCnt = 0;
            for(int j = 0; j < nums.size(); j++)
                bitCnt += (nums[j] >> i) & 1;
            
            total += bitCnt * (n - bitCnt);
        }
        return total;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/477.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #481: Magical String](https://grid47.xyz/posts/leetcode-481-magical-string-solution/) |
| --- |
