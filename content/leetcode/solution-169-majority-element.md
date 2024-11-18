
+++
authors = ["grid47"]
title = "Leetcode 169: Majority Element"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 169: Majority Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Sorting","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/majority-element/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/169.webp" 
    alt="A glowing element standing out in a sequence, symbolizing its majority status."
    caption="Solution to LeetCode 169: Majority Element Problem"
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
    int majorityElement(vector<int>& nums) {
        int e = nums[0], cnt = 1;
        map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > cnt) {
                cnt = mp[x];
                e = x;
            }
        }
        return e;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/169.md" >}}
---
{{< youtube M1IL4hz0QrE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #189: Rotate Array](https://grid47.xyz/leetcode/solution-189-rotate-array/) |
| --- |
