
+++
authors = ["grid47"]
title = "Leetcode 611: Valid Triangle Number"
date = "2024-09-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 611: Valid Triangle Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-triangle-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/611.webp" 
    alt="A set of triangle side lengths where the valid triangles glow softly, and invalid ones fade."
    caption="Solution to LeetCode 611: Valid Triangle Number Problem"
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
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int cnt = 0, n = nums.size();
        
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0, k = i - 1; j < k;) {
                if(nums[i] < nums[j] + nums[k]) {
                    cnt+= k - j;
                    k--;
                } else j++;
            }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/611.md" >}}
---
{{< youtube AZrQMv5ne54 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #617: Merge Two Binary Trees](https://grid47.xyz/leetcode/solution-617-merge-two-binary-trees/) |
| --- |
