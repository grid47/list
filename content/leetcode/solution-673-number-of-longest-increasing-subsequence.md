
+++
authors = ["grid47"]
title = "Leetcode 673: Number of Longest Increasing Subsequence"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 673: Number of Longest Increasing Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Binary Indexed Tree","Segment Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "Tuc-rjJbsXU"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/673.webp"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/673.webp" 
    alt="A sequence of numbers where the longest increasing subsequence is highlighted and softly glowing."
    caption="Solution to LeetCode 673: Number of Longest Increasing Subsequence Problem"
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
    int findNumberOfLIS(vector<int>& nums) {
        
        int res = 0, n = nums.size(), max_len = 0;
        vector<int> len(n, 0), cnt(n, 0);
        
        for(int i = 0; i < n; i++) {
            cnt[i] = 1;
            len[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(len[j] + 1 == len[i]) cnt[i] += cnt[j];
                    if(len[j] + 1 >  len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }   
            }
            if(max_len == len[i]) res += cnt[i];
            if(max_len < len[i]) {
                res = cnt[i];
                max_len = len[i];
            }
            
        }
        
        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/673.md" >}}
---
{{< youtube Tuc-rjJbsXU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #676: Implement Magic Dictionary](https://grid47.xyz/leetcode/solution-676-implement-magic-dictionary/) |
| --- |
