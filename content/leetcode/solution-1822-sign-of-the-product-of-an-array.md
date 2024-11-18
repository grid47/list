
+++
authors = ["grid47"]
title = "Leetcode 1822: Sign of the Product of an Array"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1822: Sign of the Product of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "5qwGgOEHL3U"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/sign-of-the-product-of-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sgn = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                sgn = 0;
                break;
            } else if(nums[i] > 0) {
                
            } else if(nums[i] < 0) {
                sgn *= -1;
            }
        }
        return sgn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1822.md" >}}
---
{{< youtube 5qwGgOEHL3U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1823: Find the Winner of the Circular Game](https://grid47.xyz/leetcode/solution-1823-find-the-winner-of-the-circular-game/) |
| --- |
