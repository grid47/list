
+++
authors = ["grid47"]
title = "Leetcode 128: Longest Consecutive Sequence"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 128: Longest Consecutive Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Union Find"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-consecutive-sequence/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/128.webp" 
    alt="A smooth, radiant path showing consecutive numbers, glowing brighter as the sequence length increases."
    caption="Solution to LeetCode 128: Longest Consecutive Sequence Problem"
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
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int x: nums)
            s.insert(x);
        if(s.empty()) return 0;
        int mx = 1;
        for(int i = 0; i < nums.size(); i++) {
            int y = nums[i];
            int c = 1;
            if(!s.count(y + 1))
            while(s.count(y - 1)) {
                c++;
                y = y -1;
                mx = max(mx, c);
            }
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/128.md" >}}
---
{{< youtube P6RZZMu_maU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #130: Surrounded Regions](https://grid47.xyz/posts/leetcode-130-surrounded-regions-solution/) |
| --- |
