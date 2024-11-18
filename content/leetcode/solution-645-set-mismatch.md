
+++
authors = ["grid47"]
title = "Leetcode 645: Set Mismatch"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 645: Set Mismatch in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "d-ulaeRBA64"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/645.webp"
+++



[`Problem Link`](https://leetcode.com/problems/set-mismatch/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/645.webp" 
    alt="Two sets where the mismatch is found and highlighted, with each mismatched element glowing softly."
    caption="Solution to LeetCode 645: Set Mismatch Problem"
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
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        for(int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            ans[1] ^= (i+1) ^ val;
            if (nums[val-1] < 0) ans[0] = val;
            else nums[val-1] = -nums[val-1];
        }
        ans[1] ^= ans[0];
        return ans;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/645.md" >}}
---
{{< youtube d-ulaeRBA64 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #646: Maximum Length of Pair Chain](https://grid47.xyz/leetcode/solution-646-maximum-length-of-pair-chain/) |
| --- |
