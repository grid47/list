
+++
authors = ["grid47"]
title = "Leetcode 2317: Maximum XOR After Operations "
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2317: Maximum XOR After Operations  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aNgStAspl4M"
youtube_upload_date="2022-06-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/aNgStAspl4M/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-xor-after-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        
        int mask = 0;
        
        for(auto it : nums) {
            mask |= it;
        }
        
        return mask;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2317.md" >}}
---
{{< youtube aNgStAspl4M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2319: Check if Matrix Is X-Matrix](https://grid47.xyz/leetcode/solution-2319-check-if-matrix-is-x-matrix/) |
| --- |
